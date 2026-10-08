/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : pkiworks.c
 * Description        : Entry application source file for  Aurora Networks provisioning.
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
#include "mbedtls/ecdsa.h"
#include "mbedtls/ecp.h"
#include "mbedtls/entropy.h"
#include "mbedtls/hmac_drbg.h"
#include "main.h"
#include "pkiw_device_sdk.h"
#include "stm32_factorydata.h"

extern UART_HandleTypeDef huart1;
extern void Error_Handler(void);

static const char *hex = "0123456789ABCDEF";
static mbedtls_entropy_context entropy;
static mbedtls_hmac_drbg_context drbg;

static int get_device_id(uint8_t *device_id, size_t *device_id_len);
static int gen_key_pair(CS_ecdsa_keypair *key_pair);
static int sign_hash(const uint8_t *priv_key, size_t priv_key_len,
		const uint8_t *hash, size_t hash_len, uint8_t *sig, size_t *sig_len);

void app_pkiworks_provisioning(void) {
	mbedtls_entropy_init(&entropy);
	mbedtls_hmac_drbg_init(&drbg);

	CS_init();

	CS_ecdsa_keypair keypair;
	CS_DAC_cert dac;
	CS_PAI_cert pai;
	uint8_t provision_mode = 0;
	uint8_t rv = 0;
	while (1) {
		rv = CS_start_provisioning(&keypair, &dac, &pai, &provision_mode);
		if (rv == 0) {
			break;
		}
		HAL_Delay(300);
	}

	rv = FACTORYDATA_Write(&keypair, &dac, &pai, &provision_mode);

	while (1) {
		CS_receive_status_from_ST(rv);
		HAL_Delay(3000);
	}

	mbedtls_entropy_free(&entropy);
	mbedtls_hmac_drbg_free(&drbg);
}

void pkiw_init(pkiw_callbacks_t *callbacks) {
	callbacks->get_device_id = &get_device_id;
	callbacks->gen_key_pair = &gen_key_pair;
	callbacks->sign_hash = &sign_hash;

	// The personalization string.
	const char *pers = "PKIWorks Matter Device SDK";

	// The hardware_poll function is automatically linked here by the preprocessor definition
	if (mbedtls_hmac_drbg_seed(&drbg,
			mbedtls_md_info_from_type(MBEDTLS_MD_SHA256), mbedtls_entropy_func,
			&entropy, (const unsigned char*) pers, strlen(pers)) != 0) {
		Error_Handler();
	}

	uint8_t dummy[32];
	int ret = mbedtls_hmac_drbg_random(&drbg, dummy, sizeof(dummy));
	if (ret != 0) {
		Error_Handler();
	}
}

int pkiw_comm_receive(uint8_t *msg, size_t msg_len) {
	HAL_StatusTypeDef status = HAL_UART_Receive(&huart1, msg, msg_len, 0xFFFF);
	if (status != HAL_OK) {
		return PKIW_ERR_COMM_REC_FAILED | status;
	}
	return PKIW_OK;
}

int pkiw_comm_send(const uint8_t *msg, size_t msg_len) {
	HAL_StatusTypeDef status = HAL_UART_Transmit(&huart1, msg, msg_len, 0xFFFF);
	if (status != HAL_OK) {
		return PKIW_ERR_COMM_SEND_FAILED | status;
	}
	return PKIW_OK;
}

int get_device_id(uint8_t *device_id, size_t *device_id_len) {
	uint8_t *p = device_id;

	uint32_t uid0 = HAL_GetUIDw0();
	*p++ = hex[(uid0 >> 28) & 0x0F];
	*p++ = hex[(uid0 >> 24) & 0x0F];
	*p++ = hex[(uid0 >> 20) & 0x0F];
	*p++ = hex[(uid0 >> 16) & 0x0F];
	*p++ = hex[(uid0 >> 12) & 0x0F];
	*p++ = hex[(uid0 >> 8) & 0x0F];
	*p++ = hex[(uid0 >> 4) & 0x0F];
	*p++ = hex[uid0 & 0x0F];

	uint32_t uid1 = HAL_GetUIDw1();
	*p++ = hex[(uid1 >> 28) & 0x0F];
	*p++ = hex[(uid1 >> 24) & 0x0F];
	*p++ = hex[(uid1 >> 20) & 0x0F];
	*p++ = hex[(uid1 >> 16) & 0x0F];
	*p++ = hex[(uid1 >> 12) & 0x0F];
	*p++ = hex[(uid1 >> 8) & 0x0F];
	*p++ = hex[(uid1 >> 4) & 0x0F];
	*p++ = hex[uid1 & 0x0F];

	uint32_t uid2 = HAL_GetUIDw2();
	*p++ = hex[(uid2 >> 28) & 0x0F];
	*p++ = hex[(uid2 >> 24) & 0x0F];
	*p++ = hex[(uid2 >> 20) & 0x0F];
	*p++ = hex[(uid2 >> 16) & 0x0F];
	*p++ = hex[(uid2 >> 12) & 0x0F];
	*p++ = hex[(uid2 >> 8) & 0x0F];
	*p++ = hex[(uid2 >> 4) & 0x0F];
	*p++ = hex[uid2 & 0x0F];

	*device_id_len = 24;
	return PKIW_OK;
}

int gen_key_pair(CS_ecdsa_keypair *key_pair) {
	const mbedtls_ecp_curve_info *curve_info = mbedtls_ecp_curve_info_from_name(
			"secp256r1");
	if (curve_info == NULL) {
		return 0;
	}

	mbedtls_ecp_keypair key;
	mbedtls_ecp_keypair_init(&key);

	int rv = mbedtls_ecp_gen_key(curve_info->grp_id, &key,
			mbedtls_hmac_drbg_random, &drbg);
	if (rv != 0) {
		return rv;
	}

	rv = mbedtls_mpi_write_binary(&key.private_d, key_pair->priv_key,
			PRIVATE_KEY_SIZE_MAX);
	if (rv != 0) {
		goto cleanup;
	}

	key_pair->pub_key[0] = 0x04;

	rv = mbedtls_mpi_write_binary(&key.private_Q.private_X,
			&key_pair->pub_key[1], PRIVATE_KEY_SIZE_MAX);
	if (rv != 0) {
		goto cleanup;
	}

	rv = mbedtls_mpi_write_binary(&key.private_Q.private_Y,
			&key_pair->pub_key[33], PRIVATE_KEY_SIZE_MAX);
	if (rv != 0) {
		goto cleanup;
	}

	key_pair->priv_key_len = 32;
	key_pair->pub_key_len = 65;

	cleanup: mbedtls_ecp_keypair_free(&key);
	return rv;
}

int sign_hash(const uint8_t *priv_key, size_t priv_key_len, const uint8_t *hash,
		size_t hash_len, uint8_t *sig, size_t *sig_len) {
	const mbedtls_ecp_curve_info *curve_info = mbedtls_ecp_curve_info_from_name(
			"secp256r1");
	if (curve_info == NULL) {
		return -1;
	}

	mbedtls_ecp_group grp;
	mbedtls_ecp_group_init(&grp);
	int rv = mbedtls_ecp_group_load(&grp, curve_info->grp_id);
	if (rv != 0) {
		return rv;
	}

	mbedtls_mpi r, s, d;
	mbedtls_mpi_init(&r);
	mbedtls_mpi_init(&s);
	mbedtls_mpi_init(&d);
	mbedtls_mpi_read_binary(&d, priv_key, priv_key_len);

	rv = mbedtls_ecdsa_sign(&grp, &r, &s, &d, hash, hash_len,
			mbedtls_hmac_drbg_random, &drbg);
	if (rv != 0) {
		goto cleanup;
	}

	rv = mbedtls_mpi_write_binary(&r, &sig[0], PRIVATE_KEY_SIZE_MAX);
	if (rv != 0) {
		goto cleanup;
	}

	rv = mbedtls_mpi_write_binary(&s, &sig[32], PRIVATE_KEY_SIZE_MAX);
	if (rv != 0) {
		goto cleanup;
	}

	cleanup: mbedtls_mpi_free(&r);
	mbedtls_mpi_free(&s);
	mbedtls_mpi_free(&d);

	mbedtls_ecp_group_free(&grp);

	return rv;
}
