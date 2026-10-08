@page ROT_CS_Prov_TFM
@verbatim
******************************************************************************
* @file    ROT_CS_Prov_TFM
* @author  MCD Application Team
* @brief   Provisioning for STM32WBA65I-DK1 with OEMiROT + TFM (full TrustZone).
******************************************************************************
*
* Copyright (c) 2019-2026 STMicroelectronics.
* All rights reserved.
*
* This software is licensed under terms that can be found in the LICENSE file
* in the root directory of this software component.
* If no LICENSE file comes with this software, it is provided AS-IS.
*
******************************************************************************
@endverbatim

ROT_CS_Prov_TFM Application (OEMiROT + TFM)
============================================

Overview
--------
This firmware application manages provisioning for Matter devices on STM32WBA65I-DK1 boards **with OEMiROT and TFM enabled** (full TrustZone security).

Key Features
------------
- Generates and stores Matter device credentials (DAC, PAI, key pair) on the device.
- Receives device configuration data from a JSON file via the host provisioning script.
- Communicates with the host via UART (115200 baud, 8N1).
- Automated flashing and provisioning via Python script.
- **Full secure flow with TrustZone and OTA update using a magic trailer.**

Requirements
------------
- STM32WBA65I-DK1 board with OEMiROT and TFM enabled
- Python 3.x and STM32CubeProgrammer installed on the host PC
- UART connection to host PC
- Host provisioning tool (e.g., genFactoryData.py)
- Device configuration JSON file
- Magic trailer binary and address

Provisioning Workflow
---------------------
1. Prepare the JSON configuration file.
2. Connect the board via UART.
3. Run the provisioning tool with the following command:

py genFactoryData.py --provisioning 1 --json Provisioning_FactoryData.json --flashAddr 0x81EC000 --provisioning_script STM32_provisioning.py --flashAppFW oemirot_tz_ns_app_enc_sign.bin --AppFwAddr 0x70040000 --flashMagicTrailer MagicTrailerValue.bin --flashMagicTrailerAddr 0x701BFFF0 --security 2

4. Monitor UART output for status messages.

Status Codes
------------
| Code    | Meaning                                      |
|---------|----------------------------------------------|
| 000     | Provisioning Done                            |
| 001     | Data not found                               |
| 002     | Buffer too small                             |
| 003     | Parameter error                              |
| 004     | Not initialized or synchronization failed    |

Notes
-----
- A magic trailer is required to trigger OTA update.
- Full TrustZone security is enabled.
- The private key is written to ITS with the help of TFM and the PSA API.
- Update memory addresses and file names for your project.

Troubleshooting
---------------
- Check UART connections and COM port.
- Verify board power and UART connection.
- Refer to status codes for error details.

For more details, see: https://wiki.st.com/stm32mcu/wiki/Connectivity:Matter_device_factory_data_provisioning