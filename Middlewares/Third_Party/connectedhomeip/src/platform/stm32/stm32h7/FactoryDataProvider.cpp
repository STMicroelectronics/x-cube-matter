/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include "FactoryDataProvider.h"

#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
#include <credentials/examples/DeviceAttestationCredsExample.h>
#include <credentials/examples/ExampleDACs.h>
#include <credentials/examples/ExamplePAI.h>
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0

#include <app/TestEventTriggerDelegate.h>
#include <crypto/CHIPCryptoPAL.h>
#include <lib/support/Base64.h>
#include <platform/CHIPDeviceConfig.h>
#include <platform/ConfigurationManager.h>

namespace chip {
namespace DeviceLayer {

CHIP_ERROR FactoryDataProvider::Init() {
    return CHIP_NO_ERROR;
}

FactoryDataProvider& FactoryDataProvider::GetDefaultInstance() {
    static FactoryDataProvider sInstance;
    return sInstance;
}

CHIP_ERROR FactoryDataProvider::GetCertificationDeclaration(MutableByteSpan &outBuffer)
{
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    return chip::Credentials::Examples::GetExampleDACProvider()->GetCertificationDeclaration(outBuffer);
#else
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//    uint32_t tlvDataLength;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_CERTIFICATION_DECLARATION, outBuffer.data(), outBuffer.size(), &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));
//    outBuffer.reduce_size(tlvDataLength);

//    return CHIP_NO_ERROR;
    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0
}

CHIP_ERROR FactoryDataProvider::GetFirmwareInformation(MutableByteSpan &out_firmware_info_buffer)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

CHIP_ERROR FactoryDataProvider::GetDeviceAttestationCert(MutableByteSpan &outBuffer)
{
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    return CopySpanToMutableSpan(chip::DevelopmentCerts::kDacCert, outBuffer);
#else
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//    uint32_t tlvDataLength;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_DEVICE_ATTESTATION_CERTIFICATE, outBuffer.data(), outBuffer.size(), &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));
//    outBuffer.reduce_size(tlvDataLength);

//    return CHIP_NO_ERROR;
    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0
}


CHIP_ERROR FactoryDataProvider::GetProductAttestationIntermediateCert(MutableByteSpan & outBuffer)
{
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    return CopySpanToMutableSpan(chip::DevelopmentCerts::kPaiCert, outBuffer);
#else
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//    uint32_t tlvDataLength;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_PRODUCT_ATTESTATION_INTERMEDIATE_CERTIFICATE, outBuffer.data(), outBuffer.size(), &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));
//    outBuffer.reduce_size(tlvDataLength);
//
//    return CHIP_NO_ERROR;
    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0
}

// TODO: This should be moved to a method of P256Keypair
CHIP_ERROR LoadKeypairFromRaw(ByteSpan private_key, ByteSpan public_key,
        Crypto::P256Keypair &keypair) {
    Crypto::P256SerializedKeypair serialized_keypair;
    ReturnErrorOnFailure(serialized_keypair.SetLength(private_key.size() + public_key.size()));
    memcpy(serialized_keypair.Bytes(), public_key.data(), public_key.size());
    memcpy(serialized_keypair.Bytes() + public_key.size(), private_key.data(), private_key.size());
    return keypair.Deserialize(serialized_keypair);
}

CHIP_ERROR FactoryDataProvider::SignWithDeviceAttestationKey(const ByteSpan & messageToSign, MutableByteSpan & outSignBuffer)
{
    Crypto::P256ECDSASignature signature;
    Crypto::P256Keypair keypair;

    VerifyOrReturnError(!outSignBuffer.empty(), CHIP_ERROR_INVALID_ARGUMENT);
    VerifyOrReturnError(!messageToSign.empty(), CHIP_ERROR_INVALID_ARGUMENT);
    VerifyOrReturnError(outSignBuffer.size() >= signature.Capacity(), CHIP_ERROR_BUFFER_TOO_SMALL);

    // In a non-exemplary implementation, the public key is not needed here. It is used here merely because
    // Crypto::P256Keypair is only (currently) constructable from raw keys if both private/public keys are present.
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    ReturnErrorOnFailure(LoadKeypairFromRaw(DevelopmentCerts::kDacPrivateKey, DevelopmentCerts::kDacPublicKey, keypair));
#else
//    uint8_t Privatekeybuffer[PRIVATE_KEY_LEN];
//    uint8_t Publickeybuffer[PUBLIC_KEY_LEN];
//    uint32_t tlvDataLength; // Dummy value keys values are fix
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_DEVICE_ATTESTATION_PRIVATE_KEY, Privatekeybuffer, PRIVATE_KEY_LEN, &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_DEVICE_ATTESTATION_PUBLIC_KEY, Publickeybuffer, PUBLIC_KEY_LEN, &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));
//    ReturnErrorOnFailure(LoadKeypairFromRaw(ByteSpan(Privatekeybuffer), ByteSpan(Publickeybuffer), keypair));

    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0

    ReturnErrorOnFailure(keypair.ECDSA_sign_msg(messageToSign.data(), messageToSign.size(), signature));
    return CopySpanToMutableSpan(ByteSpan { signature.ConstBytes(), signature.Length() }, outSignBuffer);
}

CHIP_ERROR FactoryDataProvider::GetSetupDiscriminator(uint16_t & setupDiscriminator)
{
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    setupDiscriminator = CHIP_DEVICE_CONFIG_USE_TEST_SETUP_DISCRIMINATOR;
    return CHIP_NO_ERROR;
#else
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//    uint32_t tlvDataLength;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_SETUP_DISCRIMINATOR, (uint8_t *) &setupDiscriminator, sizeof(setupDiscriminator), &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));

//    return CHIP_NO_ERROR;
    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0
}

CHIP_ERROR FactoryDataProvider::SetSetupDiscriminator(uint16_t setupDiscriminator)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

CHIP_ERROR FactoryDataProvider::GetSpake2pIterationCount(uint32_t & iterationCount)
{
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    iterationCount = CHIP_DEVICE_CONFIG_USE_TEST_SPAKE2P_ITERATION_COUNT;
    return CHIP_NO_ERROR;
#else
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//    uint32_t tlvDataLength;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_SPAKE2_ITERATION_COUNT, (uint8_t *) &iterationCount, sizeof(iterationCount), &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));

//    return CHIP_NO_ERROR;
    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0
}

CHIP_ERROR FactoryDataProvider::GetSpake2pSalt(MutableByteSpan & saltBuf)
{
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    CHIP_ERROR err;
    static const uint8_t kDefaultTestVerifierSalt[16] = { 0x53, 0x50, 0x41, 0x4b, 0x45, 0x32, 0x50,
            0x20, 0x4b, 0x65, 0x79, 0x20, 0x53, 0x61, 0x6c, 0x74, };

    size_t saltLen = sizeof(kDefaultTestVerifierSalt);
    if (saltBuf.size() < saltLen) {
        err= CHIP_ERROR_BUFFER_TOO_SMALL;
    }
    else {
        memcpy(saltBuf.data(), &kDefaultTestVerifierSalt[0], saltLen);
        saltBuf.reduce_size(saltLen);
        err= CHIP_NO_ERROR;
    }
    return err;
#else
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//    uint32_t tlvDataLength;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_SPAKE2_SALT, saltBuf.data(), saltBuf.size(), &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));
//    saltBuf.reduce_size(tlvDataLength);

//    return CHIP_NO_ERROR;
    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0
}

CHIP_ERROR FactoryDataProvider::GetSpake2pVerifier(MutableByteSpan & verifierBuf, size_t & verifierLen)
{
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    CHIP_ERROR err;
    static const uint8_t kDefaultTestVerifier[97] = { 0xb9, 0x61, 0x70, 0xaa, 0xe8, 0x03, 0x34,
            0x68, 0x84, 0x72, 0x4f, 0xe9, 0xa3, 0xb2, 0x87, 0xc3, 0x03, 0x30, 0xc2, 0xa6, 0x60,
            0x37, 0x5d, 0x17, 0xbb, 0x20, 0x5a, 0x8c, 0xf1, 0xae, 0xcb, 0x35, 0x04, 0x57, 0xf8,
            0xab, 0x79, 0xee, 0x25, 0x3a, 0xb6, 0xa8, 0xe4, 0x6b, 0xb0, 0x9e, 0x54, 0x3a, 0xe4,
            0x22, 0x73, 0x6d, 0xe5, 0x01, 0xe3, 0xdb, 0x37, 0xd4, 0x41, 0xfe, 0x34, 0x49, 0x20,
            0xd0, 0x95, 0x48, 0xe4, 0xc1, 0x82, 0x40, 0x63, 0x0c, 0x4f, 0xf4, 0x91, 0x3c, 0x53,
            0x51, 0x38, 0x39, 0xb7, 0xc0, 0x7f, 0xcc, 0x06, 0x27, 0xa1, 0xb8, 0x57, 0x3a, 0x14,
            0x9f, 0xcd, 0x1f, 0xa4, 0x66, 0xcf, };

    verifierLen = sizeof(kDefaultTestVerifier);
    if (verifierBuf.size() < verifierLen) {
        err = CHIP_ERROR_BUFFER_TOO_SMALL;
    }
    else {
        memcpy(verifierBuf.data(), &kDefaultTestVerifier[0], verifierLen);
        verifierBuf.reduce_size(verifierLen);
        err = CHIP_NO_ERROR;
    }
    return err;
#else
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//    uint32_t tlvDataLength;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_SPAKE2_VERIFIER, verifierBuf.data(), verifierBuf.size(), &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));
//    verifierBuf.reduce_size(tlvDataLength);
//    verifierLen = tlvDataLength;

//    return CHIP_NO_ERROR;
    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0
}

CHIP_ERROR FactoryDataProvider::GetSetupPasscode(uint32_t &setupPasscode)
{
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    setupPasscode = CHIP_DEVICE_CONFIG_USE_TEST_SETUP_PIN_CODE;
    return CHIP_NO_ERROR;
#else
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//    uint32_t tlvDataLength;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_SPAKE2_SETUP_PASSCODE, (uint8_t *) &setupPasscode, sizeof(setupPasscode), &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));

//    return CHIP_NO_ERROR;
    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0
}

CHIP_ERROR FactoryDataProvider::SetSetupPasscode(uint32_t setupPasscode)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

CHIP_ERROR FactoryDataProvider::GetVendorName(char * buf, size_t bufSize)
{
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    CHIP_ERROR err;
    if (bufSize < sizeof(CHIP_DEVICE_CONFIG_DEVICE_VENDOR_NAME)) {
        err = CHIP_ERROR_BUFFER_TOO_SMALL;
    }
    else {
        memcpy(buf, CHIP_DEVICE_CONFIG_DEVICE_VENDOR_NAME, sizeof(CHIP_DEVICE_CONFIG_DEVICE_VENDOR_NAME));
        err = CHIP_NO_ERROR;
    }
    return err;
#else
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//    uint32_t tlvDataLength;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_VENDOR_NAME, (uint8_t *) buf, bufSize, &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));
//
//    return CHIP_NO_ERROR;
    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;

//    size_t vendorNameLen = 0; // without counting null-terminator
//    return STM32Config::ReadConfigValueStr(STM32Config::kConfigKey_VendorName, buf, bufSize, vendorNameLen);
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0
}

CHIP_ERROR FactoryDataProvider::GetVendorId(uint16_t & vendorId)
{
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    vendorId = CHIP_DEVICE_CONFIG_DEVICE_VENDOR_ID;
    return CHIP_NO_ERROR;
#else
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//    uint32_t tlvDataLength;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_VENDOR_ID, (uint8_t *) &vendorId, sizeof(vendorId), &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));
//
//    return CHIP_NO_ERROR;
    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;

//    uint32_t valInt = 0;
//    err = STM32Config::ReadConfigValue(STM32Config::kConfigKey_VendorId, valInt);
//    ReturnErrorOnFailure(err);
//    vendorId = static_cast<uint16_t>(valInt);
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0
}

CHIP_ERROR FactoryDataProvider::GetProductName(char * buf, size_t bufSize) {
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    CHIP_ERROR err;
    if (bufSize < sizeof(CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_NAME)) {
        err = CHIP_ERROR_BUFFER_TOO_SMALL;
    }
    else {
        memcpy(buf, CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_NAME, sizeof(CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_NAME));
        err = CHIP_NO_ERROR;
    }
    return err;
#else
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//    uint32_t tlvDataLength;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_PRODUCT_NAME, (uint8_t *) buf, bufSize, &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));
//    return CHIP_NO_ERROR;
    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;

//    size_t productNameLen = 0; // without counting null-terminator
//    return STM32Config::ReadConfigValueStr(STM32Config::kConfigKey_ProductName, buf, bufSize, productNameLen);
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0
}

CHIP_ERROR FactoryDataProvider::GetProductId(uint16_t &productId)
{
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    productId = CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_ID;
    return CHIP_NO_ERROR;
#else
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//    uint32_t tlvDataLength;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_PRODUCT_ID, (uint8_t *) &productId, sizeof(productId), &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));
//    return CHIP_NO_ERROR;
    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;

//    uint32_t valInt = 0;
//    err = STM32Config::ReadConfigValue(STM32Config::kConfigKey_ProductId, valInt);
//    ReturnErrorOnFailure(err);
//    productId = static_cast<uint16_t>(valInt);
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0
}

CHIP_ERROR FactoryDataProvider::GetPartNumber(char * buf, size_t bufSize)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

CHIP_ERROR FactoryDataProvider::GetProductURL(char * buf, size_t bufSize)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

CHIP_ERROR FactoryDataProvider::GetProductLabel(char * buf, size_t bufSize)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

CHIP_ERROR FactoryDataProvider::GetSerialNumber(char * buf, size_t bufSize)
{
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    CHIP_ERROR err;
    if (bufSize < sizeof(CHIP_DEVICE_CONFIG_TEST_SERIAL_NUMBER)) {
        err = CHIP_ERROR_BUFFER_TOO_SMALL;
    }
    else {
        memcpy(buf, CHIP_DEVICE_CONFIG_TEST_SERIAL_NUMBER, sizeof(CHIP_DEVICE_CONFIG_TEST_SERIAL_NUMBER));
        err = CHIP_NO_ERROR;
    }
    return err;
#else
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//    uint32_t tlvDataLength;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_SERIAL_NUMBER, (uint8_t *) buf, bufSize, &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));
//    return CHIP_NO_ERROR;
    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0
}

CHIP_ERROR FactoryDataProvider::GetManufacturingDate(uint16_t & year, uint8_t & month, uint8_t & day)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

CHIP_ERROR FactoryDataProvider::GetHardwareVersion(uint16_t & hardwareVersion)
{
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    hardwareVersion = CHIP_DEVICE_CONFIG_DEVICE_HARDWARE_VERSION;
    return CHIP_NO_ERROR;
#else
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//    uint32_t tlvDataLength;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_HARDWARE_VERSION, (uint8_t *) &hardwareVersion, sizeof(hardwareVersion), &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));
//    return CHIP_NO_ERROR;
    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 0
}

CHIP_ERROR FactoryDataProvider::GetHardwareVersionString(char * buf, size_t bufSize)
{
    VerifyOrReturnError(bufSize >= sizeof(CHIP_DEVICE_CONFIG_DEFAULT_DEVICE_HARDWARE_VERSION_STRING),
                        CHIP_ERROR_BUFFER_TOO_SMALL);
    memcpy(buf, CHIP_DEVICE_CONFIG_DEFAULT_DEVICE_HARDWARE_VERSION_STRING,
           sizeof(CHIP_DEVICE_CONFIG_DEFAULT_DEVICE_HARDWARE_VERSION_STRING));
    return CHIP_NO_ERROR;
}

CHIP_ERROR FactoryDataProvider::GetSoftwareVersionString(char * buf, size_t bufSize)
{
    /* This information is managed by ConfigurationManager */
    return (DeviceLayer::ConfigurationMgr().GetSoftwareVersionString(buf, bufSize));
}

CHIP_ERROR FactoryDataProvider::GetRotatingDeviceIdUniqueId(MutableByteSpan & uniqueIdSpan)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;

//#if CHIP_ENABLE_ROTATING_DEVICE_ID && defined(CHIP_DEVICE_CONFIG_ROTATING_DEVICE_ID_UNIQUE_ID)
//    CHIP_ERROR err = CHIP_ERROR_WRONG_KEY_TYPE;
//    static_assert(ConfigurationManager::kRotatingDeviceIDUniqueIDLength >= ConfigurationManager::kMinRotatingDeviceIDUniqueIDLength,
//                  "Length of unique ID for rotating device ID is smaller than minimum.");
//
//    size_t uniqueIdLen = 0;
//    err = STM32Config::ReadConfigValueBin(STM32Config::kConfigKey_UniqueId, uniqueIdSpan.data(), uniqueIdSpan.size(), uniqueIdLen);
//    ReturnErrorOnFailure(err);
//    uniqueIdSpan.reduce_size(uniqueIdLen);
//
//    return err;
//#endif
}

CHIP_ERROR FactoryDataProvider::GetEnableKey(MutableByteSpan &enableKeySpan)
{
#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 0)
    static const uint8_t kDefaultTestEventTriggerEnableKey[TestEventTriggerDelegate::kEnableKeyLength] = {
        0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff };
    size_t enableKeyLen = sizeof(kDefaultTestEventTriggerEnableKey);
    if (enableKeySpan.size() < enableKeyLen) {
        return CHIP_ERROR_BUFFER_TOO_SMALL;
    }
    memcpy(enableKeySpan.data(), &kDefaultTestEventTriggerEnableKey[0], enableKeyLen);
    enableKeySpan.reduce_size(enableKeyLen);
    return CHIP_NO_ERROR;
#else
//    FACTORYDATA_StatusTypeDef factoryDataRes;
//    uint32_t tlvDataLength;
//
//    factoryDataRes = FACTORYDATA_GetValue(TAG_ID_ENABLE_KEY, enableKeySpan.data(), enableKeySpan.size(), &tlvDataLength);
//    VerifyOrReturnError(DATAFACTORY_OK == factoryDataRes, MapSTM32WBError(factoryDataRes));
//    enableKeySpan.reduce_size(tlvDataLength);
//    return CHIP_NO_ERROR;
    return CHIP_DEVICE_ERROR_CONFIG_NOT_FOUND;
#endif // CONFIG_STM32_FACTORY_DATA_ENABLE
}

//#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 1)
//CHIP_ERROR FactoryDataProvider::MapSTM32WBError(FACTORYDATA_StatusTypeDef factoryDataRes)
//{
//    CHIP_ERROR err;
//    switch (factoryDataRes)
//    {
//    case DATAFACTORY_OK:
//        err = CHIP_NO_ERROR;
//        break;
//    case DATAFACTORY_BUFFER_TOO_SMALL:
//        err = CHIP_ERROR_BUFFER_TOO_SMALL;
//        break;
//    case DATAFACTORY_PARAM_ERROR:
//        err = CHIP_ERROR_INVALID_ARGUMENT;
//        break;
//    default:
//        err = CHIP_ERROR_INTERNAL;
//        break;
//    }
//    return err;
//}
//#endif // CONFIG_STM32_FACTORY_DATA_ENABLE == 1

//FactoryDataProvider& FactoryDataProvider::GetDefaultInstance() {
//    static FactoryDataProvider sInstance;
//    return sInstance;
//}

} // namespace DeviceLayer
} // namespace chip
