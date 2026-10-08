/**
  ******************************************************************************
  * @file    pkiw_device_sdk.h
  * @author  PKI Center (Aurora Networks) team.
  * @brief   This file contains all the functions prototypes for generating
  *          ECDSA NIST P-256 key pair and certificate signing request (CSR).
  ******************************************************************************
  *
  * Copyright (c) 2022-2026 ARRIS Technology, Inc. All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#ifndef PKIW_DEVICE_PROVISIONING_CLIENT_H
#define PKIW_DEVICE_PROVISIONING_CLIENT_H

#include "stdint.h"
#include "st_provisioning_service.h"
	
#define DEVICE_ID_SIZE_MAX                     64

#define PKIW_OK                                 0
#define PKIW_ERR_ARG_NULL                    0x40
#define PKIW_ERR_CALLBACK_FUNC_NOT_INIT      0x41
#define PKIW_ERR_DEVICE_ID_LEN_INVALID       0x42
#define PKIW_ERR_MALLOC_FAILED               0x43
#define PKIW_ERR_PAI_LEN_INVALID             0x44
#define PKIW_ERR_DAC_LEN_INVALID             0x45
#define PKIW_ERR_MODE_LEN_INVALID            0x46
#define PKIW_ERR_MSG_NOT_RECOG               0x47
#define PKIW_ERR_PUB_KEY_MISMATCH            0x48

#define PKIW_ERR_RANDOM_GEN_FAILED           0x50
#define PKIW_ERR_EC_POINT_GEN_FAILED         0x60
#define PKIW_ERR_SIGNATURE_GEN_FAILED        0x70
#define PKIW_ERR_COMM_REC_FAILED             0x80
#define PKIW_ERR_COMM_SEND_FAILED            0x90

/** 
* @brief The definition of a callback function to retrieve device id.
*
* param[out] device_id          Unique device id.
* param[out] device_id_len      Device id length.
*
* @return PKIW_OK (0) if device id retrieval is successful or specific error code.
*/	
typedef int(*pkiw_get_device_id_callback)( uint8_t* device_id, size_t* device_id_len );

/**
* @brief The definition of a callback function to generate NIST P-256 ECDSA key pair.
*
* param[out] key_pair          Key pair.
*
* @return PKIW_OK (0) if key pair generation is successful or specific error code.
*/
typedef int(*pkiw_gen_key_pair_callback)( CS_ecdsa_keypair* key_pair );

/**
* @brief The definition of a callback function to sign given hash with the private key.
*
* param[in] priv_key          Private key raw value or handle of private key (i.e, psa_key_id_t or pkcs#11 CKA_ID)
* param[in] priv_key_len      The length of private key raw value or the size of private key handle
* param[in] hash              The hash to sign.
* param[in] hash_len          The length of the hash.
* param[out] sig              ECDSA P-256 signature over the hash. The signature shall be the concatenation of r and s.
* param[in/out] sig_len       The length of sig buffer as input, and the actual length of the signature as output.
*
* @return PKIW_OK (0) if signing is successful or specific error code.
*/
typedef int(*pkiw_sign_hash_callback)(const uint8_t* priv_key, size_t priv_key_len, const uint8_t* hash, size_t hash_len, uint8_t* sig, size_t* sig_len );

/**
 * @brief
 */
typedef struct pkiw_callbacks
{
	/** @brief A callback function to get device id. */
	pkiw_get_device_id_callback get_device_id;

	/** @brief A callback function to generate key pair. */
	pkiw_gen_key_pair_callback gen_key_pair;

	/** @brief A callback function to sign hash. */
	pkiw_sign_hash_callback sign_hash;

} pkiw_callbacks_t;

/**
* @brief Get the version of device SDK.
*
* @return The version of device SDK.
*/
char* pkiw_get_version( void );

/**
* @brief Initialize components.
*
* param[out] callbacks       A collection of callback functions.
*/
extern void pkiw_init( pkiw_callbacks_t* callbacks );

/**
* @brief Sends the given message to proxy provision client.
* 
* param[in] msg                Message to be sent.
* param[in] msg_len            Message length.
*
* @return PKIW_OK (0) if sending message is successful; otherwise, specific error code.
*/
extern int pkiw_comm_send( const uint8_t* msg, size_t msg_len );

/**
* @brief Receives the message from proxy provision client.
*
* param[out] msg                Message received.
* param[in] msg_len             Expected length of the message.
*
* @return PKIW_OK (0) if receiving message is successful; otherwise, specific error code.
*/
extern int pkiw_comm_receive( uint8_t* msg, size_t msg_len );

#endif /* PKIW_DEVICE_PROVISIONING_CLIENT_H */
