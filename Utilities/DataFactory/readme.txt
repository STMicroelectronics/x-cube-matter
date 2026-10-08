@page genFactoryData
  @verbatim
  ******************************************************************************
  * @file    genFactoryData.py
  * @author  MCD Application Team
  * @brief   This file lists the modification done by STMicroelectronics on
  *          Matter for integration with STM32Cube solution.
  ******************************************************************************
  *
  * Copyright (c) 2019-2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @endverbatim

genFactoryData Tool
===================

Overview
--------
The `genFactoryData` tool is a Python script designed to provision Matter certificates and firmware for STM32 microcontrollers, with a focus on STM32WBA/STM32U5 boards featuring a Cortex-M33 core and TrustZone security. STM32U5 board support provisioning only with OEMiROT application
It automates the process of preparing devices for Matter compliance by managing the provisioning workflow, flashing firmware, and executing provisioning scripts, including secure flows for TrustZone-enabled devices.

Note: Matter credentials (DAC, PAI, keypair) are generated on the STM32 target during the provisioning process by the provisioning firmware. They are not required in the configuration file.

Key Features
------------
- On-Device Matter Credential Generation: The provisioning firmware running on the STM32 generates the DAC, PAI, and keypair securely on the device.
- Multiple Security Levels: Supports classic (no security), OEMiROT only, and OEMiROT + TFM provisioning flows.
- Flexible Data Handling: Supports both JSON and binary formats for device configuration.
- Firmware Flashing: Programs application firmware to user-defined memory addresses.
- Scripted Provisioning: Executes custom provisioning scripts for advanced workflows.
- Multi-device Support: Handles concurrent provisioning of multiple devices.
- Serial Port Management: Lists and checks available serial ports for device communication.

Requirements
------------
- Python 3.x
- STM32CubeProgrammer (default path: `c:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin`)
- Python packages:
    pyserial, concurrent.futures, argparse, json, struct, subprocess, tempfile, os, re, ssl, enum, threading, datetime
- TrustZone scripts (for secure flows):
    - regression.bat: Puts the board in a clean state, erases memory, and configures security registers.
    - provisioning.bat: Flashes the provisioning firmware with OEMiROT and TFM for secure boot and secure services.
    - Location: Both scripts are available at for OEMiRoT (security = 1):
      Projects\STM32WBA65I-DK1\ROT_Provisioning_STM_Prov_OEMiRoT\OEMiROT
    - Location: Both scripts are available at for TFM (security = 2):
      Projects\STM32WBA65I-DK1\ROT_Provisioning_STM_Prov_TFM\OEMiROT

Command Line Arguments
----------------------
--provisioning           Required. 0 or 1 to enable/disable provisioning.
--json                   Path to JSON file with device configuration (exclusive with --binary).
--binary                 Path to binary file with device configuration (exclusive with --json).
--flashProvisioningFW    Path to provisioning firmware (required if provisioning is enabled, non-secure flow).
--provisioning_script    Path to provisioning script (required if provisioning is enabled).
--flashAppFW             Path to Matter application firmware (required if provisioning is enabled).
--AppFwAddr, -afwa       Flash address for application firmware.
--flashAddr, -fa         Required. Flash address for the binary output file.
--programmerPath, -pp    Path to STM32CubeProgrammer binary.
--externalLoader, -el    External loader file (default: M95P32_STM32WBA65I-DK).
--security               Security level: 0 (no security), 1 (OEMiROT only), 2 (OEMiROT + TFM).
--platform               supported platform: 'wba' or 'u5' only used if security >= 1.
--flashMagicTrailer      Path to the magic trailer binary (required if --security 1 or 2).
--flashMagicTrailerAddr  Flash address for the magic trailer (required if --security 1 or 2).
--verbose, -v            Enable verbose output for detailed logs.

Security Modes (`--security`)
-----------------------------
- `0` : No security (classic provisioning, no OEMiROT, no TFM)
- `1` : OEMiROT only (secure bootloader, OTA update with magic trailer, no TFM)
- `2` : OEMiROT + TFM (full TrustZone and secure services, OTA update with magic trailer)

Usage Examples
--------------

1. No Security (Classic Flow)
-----------------------------
This mode is used for a standard STM32WBA board without OEMiROT or TrustZone enable.
No secure flow is triggered; the tool simply flashes the provisioning firmware and the application.

Command:
    py genFactoryData.py ^
      --provisioning 1 ^
      --json Provisioning_FactoryData.json ^
      --flashAddr 0x81EC000 ^
      --flashProvisioningFW STM_Provisioning.bin ^
      --provisioning_script STM32_provisioning.py ^
      --flashAppFW Lighting-App.bin ^
      --AppFwAddr 0x08000000 ^
      --security 0

2. OEMiROT Only (Secure Bootloader, OTA update, No TFM)
-------------------------------------------------------
This mode is used when your STM32WBA or STM32U5 board is configured with OEMiROT but without TFM.
The --security 1 argument enables the OEMiROT secure flow, including OTA update with the magic trailer.

Command for STM32WBA:
    py genFactoryData.py ^
      --provisioning 1 ^
      --json Provisioning_FactoryData.json ^
      --flashAddr 0x81EC000 ^
      --provisioning_script STM32_provisioning.py ^
      --flashAppFW oemirot_tz_ns_app_enc_sign.bin ^
      --AppFwAddr 0x70006000 ^
      --flashMagicTrailer MagicTrailerValue.bin ^
      --flashMagicTrailerAddr 0x701CBFF0 ^
      --security 1 ^
      --platform wba

Command for STM32U5:
    py genFactoryData.py ^
      --provisioning 1 ^
      --json Provisioning_FactoryData.json ^
      --flashAddr 0x81EC000 ^
      --provisioning_script STM32_provisioning.py ^
      --flashAppFW sbsfu_app_enc_sign.bin ^
      --AppFwAddr 0x08100000 ^
      --flashMagicTrailer MagicTrailerValue.bin ^
      --flashMagicTrailerAddr 0x081E5FF0 ^
      --security 1 ^
      --platform u5

3. OEMiROT + TFM (Full Security)
--------------------------------
This mode is used when your STM32WBA board is configured with both OEMiROT and TFM (TrustZone).
The private key is write inside the ITS with the help of the TFM and the PSA API.

Command:
    py genFactoryData.py ^
      --provisioning 1 ^
      --json Provisioning_FactoryData.json ^
      --flashAddr 0x81EC000 ^
      --provisioning_script STM32_provisioning.py ^
      --flashAppFW oemirot_tz_ns_app_enc_sign.bin ^
      --AppFwAddr 0x70040000 ^
      --flashMagicTrailer MagicTrailerValue.bin ^
      --flashMagicTrailerAddr 0x701BFFF0 ^
      --security 2
      --platform wba

Key Points:
- --security 1 and 2 trigger an OTA update using the magic trailer.
- --flashMagicTrailer and --flashMagicTrailerAddr are required for both --security 1 and 2.
- The application firmware is flashed in the non-secure region.
- The scripts regression.bat and provisioning.bat must be present in Projects\STM32WBA65I-DK1\ROT_STM_Factory_Provisioning\OEMiROT for secure flows.

Post-Provisioning Firmware Update Flow
--------------------------------------

OEMiROT Only or OEMiROT + TFM (OTA update)
------------------------------------------
- The application firmware (e.g., oemirot_tz_ns_app_enc_sign.bin) is first flashed in the external flash (non-secure area).
- The magic trailer is flashed at the end of the download slot.
- This triggers an OTA (Over-The-Air) update process:
    - On reboot, the bootloader (OEMiROT/TFM) detects the magic trailer.
    - The provisioning firmware is automatically replaced by the Matter application image.
    - The device then boots into the Matter application, which is now active and ready for commissioning.

No Security (Classic)
---------------------
- The provisioning firmware is first flashed and used to generate credentials and configure the device.
- After provisioning is complete:
    - The provisioning firmware image is erased or overwritten.
    - The Matter application firmware (e.g., Lighting-App.bin) is flashed directly at the application address.
    - The device boots directly into the Matter application.

Provisioning Script Details
--------------------------
The provisioning script (e.g., STM32_provisioning.py) manages the communication with the STM32 target over a serial (COM) port to perform the provisioning process. It synchronizes with the device, triggers provisioning, and interprets the result codes sent back by the STM32 firmware.

How It Works:
- The script opens the specified COM port at 115200 baud.
- It sends an initialization command ("Init\n") and waits for the STM32 to respond with the "Start_provisioning" keyword, indicating synchronization is complete.
- Once synchronized, the script listens for a line matching the pattern finish:XYZ, where XYZ is a three-digit status code returned by the STM32.
- The script interprets this code and prints a corresponding message.

Return Codes:
    0x0000  Provisioning Done                         - Provisioning completed successfully.
    0x0001  Data not found                            - Required data was not found on the device.
    0x0002  Buffer too small                          - The buffer provided was too small.
    0x0003  Parameter error                           - There was a parameter error in the request.
    0x0004  STM32 not init or fail in synchronization - The STM32 did not initialize or failed to sync.
    0xFFFE  Provisioning completed with unknown error - An unknown error occurred during provisioning.
    0xFFFF  Provisioning interrupted by user          - The process was interrupted by the user.

Typical Flow:
1. Start: The script prints a start message and attempts to open the COM port.
2. Synchronization: It sends "Init\n" repeatedly until it receives "Start_provisioning" from the STM32 or times out.
3. Provisioning: Once synchronized, it waits for the STM32 to send a finish:XYZ message.
4. Result Handling: The script interprets the code and prints a color-coded message indicating success or the type of error.
5. Close: The COM port is closed at the end of the process.

Example Output:
    [GREEN]Start third party provisioning[RESET]
    [GREEN]Provisioning Done[RESET]
or, in case of error:
    [RED]Data not found[RESET]

Notes:
- The script uses a timeout of 30 seconds for both synchronization and result waiting.
- All serial communication is at 115200 baud, 8N1.
- The script is robust to user interruption (Ctrl+C) and unexpected serial errors.

Notes
-----
- Matter credentials (DAC, PAI, keypair) are always generated on the device by the provisioning firmware.
- The private key is write in ITS when security = 2
- The secure flow (--security 1 or 2) requires the presence and correct configuration of regression.bat and provisioning.bat.
- The magic trailer is required for both --security 1 and 2.
- Always adapt addresses and file names to your project and memory mapping.
- For production provisioning, ensure that the provisioning firmware implements secure and unique credential generation for each device.

Troubleshooting
---------------
- Make sure all memory addresses and file paths are correct and match your board’s memory map.
- If you encounter serial port issues, verify that no other application is using the port and that the board is properly connected.

For further details, refer to the wikipage: https://wiki.st.com/stm32mcu/wiki/Connectivity:Matter_device_factory_data_provisioning