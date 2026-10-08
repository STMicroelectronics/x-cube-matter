@page STM_Provisioning
@verbatim
******************************************************************************
* @file    Matter/STM_Provisioning
* @author  MCD Application Team
* @brief   Non-secure provisioning for STM32WBA65I-DK1 (no OEMiROT, no TFM).
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

STM_Provisioning Application (Non-Secure)
==========================================

Overview
--------
This firmware application manages the non-secure provisioning process for Matter devices on STM32WBA65I-DK1 boards **without OEMiROT or TrustZone**.

Key Features
------------
- Generates and stores Matter device credentials (DAC, PAI, key pair) directly on the device.
- Receives device configuration data from a JSON file via the host provisioning script.
- Communicates with the host via UART (115200 baud, 8N1).
- Fully automated flashing and provisioning via Python script.

Requirements
------------
- STM32WBA65I-DK1 board
- Python 3.x and STM32CubeProgrammer installed on the host PC
- UART connection to host PC
- Host provisioning tool (e.g., genFactoryData.py)
- Device configuration JSON file

Provisioning Workflow
---------------------
1. Prepare the JSON configuration file.
2. Connect the board via UART.
3. Run the provisioning tool with the following command:

py genFactoryData.py --provisioning 1 --json Provisioning_FactoryData.json --flashAddr 0x81EC000 --flashProvisioningFW STM_Provisioning.bin --provisioning_script STM32_provisioning.py --flashAppFW Lighting-App.bin --AppFwAddr 0x08000000 --security 0

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
- This application is for non-secure provisioning only.
- Update memory addresses and file names for your project.

Troubleshooting
---------------
- Check UART connections and COM port.
- Verify board power and UART connection.
- Refer to status codes for error details.

For more details, see: https://wiki.st.com/stm32mcu/wiki/Connectivity:Matter_device_factory_data_provisioning