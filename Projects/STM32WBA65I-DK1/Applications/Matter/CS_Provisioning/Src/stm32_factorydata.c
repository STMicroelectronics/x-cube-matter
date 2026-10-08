/**
 ******************************************************************************
 * @file    stm32_factorydata.c
 * @author  MCD Application Team
 * @brief   Middleware between matter factory data and external flash ,
 *          to manage factory data needed for Matter
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32_factorydata.h"
#include "storage_interface.h"
#include "main.h"
#include <string.h>

/* Private defines -----------------------------------------------------------*/
#define HEADER_SIZE 8
#define FACTORY_DATA_START_ADDR 0x81EC000U
#define FACTORY_DATA_START_ADDR_PTR ((void * const) FACTORY_DATA_START_ADDR)
#define FACTORY_DATA_END_ADDR 0x81FAFFFU
#define DATA_MAX_LENGTH 603
#define MAGIC_KEY_WORD 0xACACACACU
#define DEFAULT_VALUE_U32 0xFFFFFFFFU
#define FACTORY_DATA_LENGTH 16384

/* Private variables ---------------------------------------------------------*/
typedef struct {
	uint32_t tag_id;
	uint32_t data_length;
} header;

static uint8_t Factory_Data_buff[FACTORY_DATA_LENGTH];

/* Private functions prototypes-----------------------------------------------*/
static uint8_t* Get_MagicKeyWordLocation(void);
static FACTORYDATA_StatusTypeDef Set_Certificates(uint8_t *location,
		CS_ecdsa_keypair *keypair, CS_DAC_cert *dac, CS_PAI_cert *pai,
		uint8_t *mode);

/*************************************************************
 *
 * PUBLIC FUNCTIONS
 *
 *************************************************************/

uint8_t FACTORYDATA_Write(CS_ecdsa_keypair *keypair, CS_DAC_cert *dac,
		CS_PAI_cert *pai, uint8_t *provision_mode) {

	uint8_t err = DATAFACTORY_DATA_NOT_FOUND;
	uint8_t *Location = Factory_Data_buff;

	if ((keypair == NULL) || (dac == NULL) || (pai == NULL)
			|| (provision_mode == NULL)) {
		return DATAFACTORY_PARAM_ERROR;
	}

	// search for keyword location
	Location = Get_MagicKeyWordLocation();
	if (Location == Factory_Data_buff) {
		return err;
	} else {
		// Write Certificates in ram buffer
		err = Set_Certificates(Location, keypair, dac, pai, provision_mode);
		if (err == DATAFACTORY_OK) {
			// delete old factory data
			FLASH_If_Erase_Size(FACTORY_DATA_START_ADDR_PTR,
			FACTORY_DATA_LENGTH);
			//bump ram buffer in factory data location
			err = FLASH_If_Write(FACTORY_DATA_START_ADDR_PTR, Factory_Data_buff,
			FACTORY_DATA_LENGTH);
		}
	}

	return err;
}

/*************************************************************
 *
 * LOCAL FUNCTIONS
 *
 *************************************************************/

static uint8_t* Get_MagicKeyWordLocation(void) {
	header Header_tag;
	uint8_t Header_data[HEADER_SIZE];
	uint8_t *location_tmp = Factory_Data_buff;
	uint8_t *out_Location = Factory_Data_buff;

	memset(Factory_Data_buff, 0xff, FACTORY_DATA_LENGTH);
	memcpy(Factory_Data_buff, FACTORY_DATA_START_ADDR_PTR, FACTORY_DATA_LENGTH);

	// read all header until find the right tag
	for (int i = 0; i < FACTORY_DATA_LENGTH; i++) {
		memcpy(Header_data, location_tmp, HEADER_SIZE);
		//retrieve header with tag_id and data_length
		Header_tag.tag_id = Header_data[0] + ((Header_data[1]) << 8)
				+ ((Header_data[2]) << 16) + ((Header_data[3]) << 24);
		Header_tag.data_length = Header_data[4] + ((Header_data[5]) << 8)
				+ ((Header_data[6]) << 16) + ((Header_data[7]) << 24);

		// no more data
		if ((Header_tag.tag_id == DEFAULT_VALUE_U32)
				&& (Header_tag.data_length == DEFAULT_VALUE_U32)) {
			// cannot find magic key word
			break;
		}

		// check if provisioning is already happen
		if ((Header_tag.tag_id == TAG_ID_DEVICE_ATTESTATION_CERTIFICATE)
				|| (Header_tag.tag_id
						== TAG_ID_PRODUCT_ATTESTATION_INTERMEDIATE_CERTIFICATE)
				|| (Header_tag.tag_id == TAG_ID_DEVICE_ATTESTATION_PUBLIC_KEY)
				|| (Header_tag.tag_id == TAG_ID_DEVICE_ATTESTATION_PRIVATE_KEY)) {
			break;
		}
		// check if we find the magic key word
		if (Header_tag.tag_id == MAGIC_KEY_WORD) {
			out_Location = location_tmp;
			break;
		}
		// move to the next data
		if ((location_tmp + Header_tag.data_length + HEADER_SIZE)
				> (Factory_Data_buff + FACTORY_DATA_LENGTH)) {
			break;
		} else {

			location_tmp += Header_tag.data_length + HEADER_SIZE;
		}
	}

	return out_Location;
}

static FACTORYDATA_StatusTypeDef Set_Certificates(uint8_t *location,
		CS_ecdsa_keypair *keypair, CS_DAC_cert *dac, CS_PAI_cert *pai,
		uint8_t *mode) {
	header Header_tag;
	uint8_t err = DATAFACTORY_OK;

	// write DAC
	Header_tag.tag_id = TAG_ID_DEVICE_ATTESTATION_CERTIFICATE;
	Header_tag.data_length = dac->len;
	memcpy(location, &Header_tag, sizeof(header));
	location += HEADER_SIZE;
	memcpy(location, dac->val, Header_tag.data_length);
	location += Header_tag.data_length;

	// write PAI
	Header_tag.tag_id = TAG_ID_PRODUCT_ATTESTATION_INTERMEDIATE_CERTIFICATE;
	Header_tag.data_length = pai->len;
	memcpy(location, &Header_tag, sizeof(header));
	location += HEADER_SIZE;
	memcpy(location, pai->val, Header_tag.data_length);
	location += Header_tag.data_length;

	// write Public_key
	Header_tag.tag_id = TAG_ID_DEVICE_ATTESTATION_PUBLIC_KEY;
	Header_tag.data_length = keypair->pub_key_len;
	memcpy(location, &Header_tag, sizeof(header));
	location += HEADER_SIZE;
	memcpy(location, keypair->pub_key, Header_tag.data_length);
	location += Header_tag.data_length;

	// write private key
	Header_tag.tag_id = TAG_ID_DEVICE_ATTESTATION_PRIVATE_KEY;
	Header_tag.data_length = keypair->priv_key_len;
	memcpy(location, &Header_tag, sizeof(header));
	location += HEADER_SIZE;
	memcpy(location, keypair->priv_key, Header_tag.data_length);
	location += Header_tag.data_length;

	// write magic key word at end of the factory data
	Header_tag.tag_id = MAGIC_KEY_WORD;
	Header_tag.data_length = DEFAULT_VALUE_U32;
	memcpy(location, &Header_tag, sizeof(header));

	return err;
}
