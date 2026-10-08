/**
 ******************************************************************************
 * File Name          : app_pkiworks_psa.c
 * Description        : Entry application source file for Aurora Networks provisioning.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2019-2021 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include "app_pkiworks.h"
#include "main.h"
#include "pkiw_device_sdk.h"
#include "psa/crypto.h"
#include "stm32_factorydata.h"
#include "storage_interface.h"

extern UART_HandleTypeDef huart1;
extern void Error_Handler(void);

static const char* hex="0123456789ABCDEF";

// private functions
static int get_device_id(uint8_t* device_id, size_t* device_id_len);
static int gen_key_pair(CS_ecdsa_keypair* key_pair);
static int sign_hash(const uint8_t* priv_key, size_t priv_key_len, const uint8_t* hash, size_t hash_len, uint8_t* sig, size_t* sig_len);

void app_pkiworks_provisioning(void)
{
	uint8_t rv = 0;
	CS_init();

	CS_ecdsa_keypair keypair;
	CS_DAC_cert dac;
	CS_PAI_cert pai;
	uint8_t provision_mode;

	while (1)
	{
		rv = CS_start_provisioning(&keypair, &dac, &pai, &provision_mode);
		if (rv == 0)
		{
			break;
		}
		HAL_Delay(300);
	}

	rv = FACTORYDATA_Write(&keypair, &dac, &pai);

	while (1)
	{
		CS_receive_status_from_ST(rv);
		HAL_Delay(3000);
	}
}

void pkiw_init(pkiw_callbacks_t* callbacks)
{
	callbacks->get_device_id = &get_device_id;
	callbacks->gen_key_pair = &gen_key_pair;
	callbacks->sign_hash = &sign_hash;
}

int pkiw_comm_receive(uint8_t* msg, size_t msg_len)
{
	HAL_StatusTypeDef status = HAL_UART_Receive(&huart1, msg, msg_len, 0xFFFF);
	if (status != HAL_OK) {
		return PKIW_ERR_COMM_REC_FAILED | status;
	}
	return PKIW_OK;
}

int pkiw_comm_send(const uint8_t* msg, size_t msg_len)
{
	HAL_StatusTypeDef status = HAL_UART_Transmit(&huart1, msg, msg_len, 0xFFFF);
	if (status != HAL_OK) {
		return PKIW_ERR_COMM_SEND_FAILED | status;
	}
	return PKIW_OK;
}

int get_device_id(uint8_t* device_id, size_t* device_id_len)
{
  	uint8_t* p = device_id;

	uint32_t uid0 = HAL_GetUIDw0();
	*p++ = hex[(uid0 >> 28) & 0x0F];
	*p++ = hex[(uid0 >> 24) & 0x0F];
	*p++ = hex[(uid0 >> 20) & 0x0F];
	*p++ = hex[(uid0 >> 16) & 0x0F];
	*p++ = hex[(uid0 >> 12) & 0x0F];
	*p++ = hex[(uid0 >>  8) & 0x0F];
	*p++ = hex[(uid0 >>  4) & 0x0F];
	*p++ = hex[  uid0 & 0x0F ];

	uint32_t uid1 = HAL_GetUIDw1();
	*p++ = hex[(uid1 >> 28) & 0x0F];
	*p++ = hex[(uid1 >> 24) & 0x0F];
	*p++ = hex[(uid1 >> 20) & 0x0F];
	*p++ = hex[(uid1 >> 16) & 0x0F];
	*p++ = hex[(uid1 >> 12) & 0x0F];
	*p++ = hex[(uid1 >>  8) & 0x0F];
	*p++ = hex[(uid1 >>  4) & 0x0F];
	*p++ = hex[  uid1 & 0x0F ];

	uint32_t uid2 = HAL_GetUIDw2();
	*p++ = hex[(uid2 >> 28) & 0x0F];
	*p++ = hex[(uid2 >> 24) & 0x0F];
	*p++ = hex[(uid2 >> 20) & 0x0F];
	*p++ = hex[(uid2 >> 16) & 0x0F];
	*p++ = hex[(uid2 >> 12) & 0x0F];
	*p++ = hex[(uid2 >>  8) & 0x0F];
	*p++ = hex[(uid2 >>  4) & 0x0F];
	*p++ = hex[  uid2 & 0x0F];

	*device_id_len = 24;
	return PKIW_OK;
}

int gen_key_pair(CS_ecdsa_keypair* key_pair)
{
	/* Initialize PSA Crypto */
	psa_status_t status = psa_crypto_init();
	if (status != PSA_SUCCESS)
	{
		return status;
	}

	// Delete the key if exists
	psa_key_id_t key_id;
	status = psa_open_key(DEVICE_ATTESTATION_PRIVATE_KEY_ID_USER, &key_id);
	if(status == PSA_SUCCESS)
	{
		/* Destroy the private key */
        status = psa_destroy_key(key_id);
        if(status != PSA_SUCCESS)
        {
        	return status;
        }
	}

	/* Set the attributes of the key as needed */
	psa_key_attributes_t attributes = psa_key_attributes_init();
	psa_set_key_usage_flags(&attributes, PSA_KEY_USAGE_SIGN_MESSAGE | PSA_KEY_USAGE_SIGN_HASH);
	psa_set_key_algorithm(&attributes, PSA_ALG_ECDSA(PSA_ALG_SHA_256));
	psa_set_key_type(&attributes, PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1));
	psa_set_key_bits(&attributes, 8U * PRIVATE_KEY_LEN);
	psa_set_key_lifetime(&attributes,
					PSA_KEY_LIFETIME_FROM_PERSISTENCE_AND_LOCATION(
							PSA_KEY_PERSISTENCE_DEFAULT,
							PSA_KEY_LOCATION_LOCAL_STORAGE));
	psa_set_key_id(&attributes, DEVICE_ATTESTATION_PRIVATE_KEY_ID_USER);

	/* Generate a key pair */
	status = psa_generate_key(&attributes, &key_id);
	if (status != PSA_SUCCESS)
	{
		goto cleanup;
	}
	psa_reset_key_attributes(&attributes);

	/* Export the public key in the following format: 0x04 || X || Y (65 bytes) */
	uint8_t exported[65];
	size_t exported_length = 0;
	status = psa_export_public_key(key_id, exported, sizeof(exported), &exported_length);
	if (status != PSA_SUCCESS)
	{
		goto cleanup;
	}

	// Copy the public key value
	memcpy(key_pair->pub_key, exported, exported_length);
	key_pair->pub_key_len = exported_length;

	// Set private key handle to the first 4 bytes of priv_key array
	key_pair->priv_key[0] = ( key_id >> 24 ) & 0xFF;
	key_pair->priv_key[1] = ( key_id >> 16 ) & 0xFF;
	key_pair->priv_key[2] = ( key_id >> 8 ) & 0xFF;
	key_pair->priv_key[3] = key_id & 0xFF;
	key_pair->priv_key_len = sizeof(psa_key_id_t);

cleanup:
	//mbedtls_psa_crypto_free();

	return status;
}

int sign_hash(const uint8_t* priv_key, size_t priv_key_len, const uint8_t* hash, size_t hash_len, uint8_t* sig, size_t* sig_len)
{
	/* Initialize PSA Crypto */
	psa_status_t status = psa_crypto_init();
	if (status != PSA_SUCCESS)
	{
		return PKIW_ERR_SIGNATURE_GEN_FAILED;
	}

	// Get key id from SDK
	psa_key_id_t priv_key_id = (priv_key[0] << 24) | (priv_key[1] << 16) | (priv_key[2] << 8) | priv_key[3];

	// Get key_id from TrustZone
	psa_key_id_t key_id;
	status = psa_open_key(DEVICE_ATTESTATION_PRIVATE_KEY_ID_USER, &key_id);
	if(status != PSA_SUCCESS)
	{
		return PKIW_ERR_SIGNATURE_GEN_FAILED;
	}

	// Just making sure priv_key_id & key_id are a match
	if(priv_key_id != key_id )
	{
		status = PKIW_ERR_SIGNATURE_GEN_FAILED;
		goto cleanup;
	}

	// Generate the signature (raw r||s)
	status = psa_sign_hash(key_id, PSA_ALG_ECDSA(PSA_ALG_SHA_256), hash, hash_len, sig, *sig_len, sig_len);
	if (status == PSA_SUCCESS)
	{
		status = PKIW_OK;
	}
	else
	{
		status = PKIW_ERR_SIGNATURE_GEN_FAILED;
	}

cleanup:
	psa_close_key(key_id);

	return status;
}
