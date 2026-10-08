#ifndef _ST_PROVISION_SERVICE_H 
#define _ST_PROVISION_SERVICE_H

#include <stdint.h>
#include <stddef.h>

#define PRIVATE_KEY_SIZE_MAX   32
#define PUBLIC_KEY_SIZE_MAX    65
#define DAC_SIZE_MAX          600
#define PAI_SIZE_MAX          600

/**
* @brief Holds ECDSA private and public keys.
*/
typedef struct  {
  
  /** @brief Private key value */
  uint8_t priv_key[PRIVATE_KEY_SIZE_MAX];
  
  /** @brief Private key length */
  size_t priv_key_len;
  
  /** @brief Public key value */
  uint8_t pub_key[PUBLIC_KEY_SIZE_MAX];
  
  /** @brief Public key length */
  size_t pub_key_len;
  
} CS_ecdsa_keypair;


/**
* @brief Hold DAC information.
*/
typedef struct {
  
  /** @brief DAC (Device Attestation Certificate) value */
  uint8_t val[DAC_SIZE_MAX];
  
  /** @brief DAC length */
  size_t len;
  
} CS_DAC_cert;


/**
* @brief Holds PAI certificate information.
*/
typedef struct {
  
  /** @brief PAI (Product Attestation Intermediate) certificate value */
  uint8_t val[PAI_SIZE_MAX];
  
  /** @brief PAI length */
  size_t len;
  
} CS_PAI_cert;


/**
* @brief Initialize CS components.
*/
void CS_init( void );

/**
* @brief Start device provisioning process.
*
* param[out] keypair                ECDSA Key pair.
* param[out] DAC                    DAC (Device Attestation Certificate).
* param[out] PAI                    PAI (Product Attestation Intermediate) certificate.
* param[out] provision_mode         Value indicating whether the provisioning is for testing or production.
*
* @return 0 if provisioning is successful; otherwise, specific error code
*/
uint8_t CS_start_provisioning( CS_ecdsa_keypair *keypair, CS_DAC_cert *DAC, CS_PAI_cert *PAI, uint8_t* provision_mode );

/**
* @brief Receives the status of certificate and key storage process.
*
* param[in] status        The stutus of certificate and key storage process.
*/
void CS_receive_status_from_ST( uint8_t status );

#endif
