@page ROT_STM_Prov_OEMiRoT
@verbatim
******************************************************************************
* @file    ROT_STM_Prov_OEMiRoT
* @author  MCD Application Team
* @brief   Provisioning for NUCLEO-U575ZI-Q with OEMiROT/SBSFU (secure bootloader, OTA).
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

ROT_STM_Prov_OEMiRoT Application (OEMiROT)
======================================

Overview
--------
This firmware application manages provisioning for Matter devices on NUCLEO-U575ZI-Q boards **with OEMiROT/SBSFU enabled** (secure bootloader, no TFM).

Key Features
------------
- Generates and stores Matter device credentials (DAC, PAI, key pair) on the device.
- Receives device configuration data from a JSON file via the host provisioning script.
- Automated flashing and provisioning via Python script.
- **OTA update is triggered using a magic trailer after provisioning.**

Requirements
------------
- NUCLEO-U575ZI-Q board with OEMiROT/SBSFU enabled
- Python 3.x and STM32CubeProgrammer installed on the host PC
- UART connection to host PC
- Host provisioning tool (e.g., genFactoryData.py)
- Device configuration JSON file
- Magic trailer binary and address

Provisioning Workflow
---------------------
1. Prepare the JSON configuration file.
2. Connect the board via UART.
3. Compile SBSFU_Boot and SBSFU_Appli projects with STM32CubeIDE.
4. Generate the Matter application with factory data enabled (`NUCLEO-U575ZI-Q\Applications\ROT_Lighting_OEMiRoT\SBSFU_Appli\Binary\sbsfu_app_enc_sign.bin`).
5. Run the provisioning tool with the following command:

py genFactoryData.py --provisioning 1 --json Provisioning_FactoryData.json --flashAddr 0x81EC000 --provisioning_script STM32_provisioning.py --flashAppFW sbsfu_app_enc_sign.bin --AppFwAddr 0x08100000 --flashMagicTrailer MagicTrailerValue.bin --flashMagicTrailerAddr 0x081E5FF0 --security 1 --platform u5

6. Monitor UART output for status messages.

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
- AppFwAddr is the address of download slot 1.
- A magic trailer is required to trigger OTA update.
- flashMagicTrailerAddr corresponds to the end of download slot 1.
- Update memory addresses and file names for your project.

Troubleshooting
---------------
- Check UART connections and COM port.
- Verify board power and UART connection.
- Refer to status codes for error details.

For more details, see: https://wiki.st.com/stm32mcu/wiki/Connectivity:Matter_device_factory_data_provisioning