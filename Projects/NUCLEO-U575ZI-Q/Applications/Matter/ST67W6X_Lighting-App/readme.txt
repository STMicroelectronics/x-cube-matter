****
  @page ST67W6X_Lighting-App
  @verbatim
  ***************************************************************************************
  * @file    Projects\NUCLEO-U575ZI-Q\Applications\Matter\ST67W6X_Lighting-App\readme.txt
  * @author  MCD Application Team
  * @brief   This file lists the modifications made by STMicroelectronics to
  *          Matter for integration with the STM32Cube solution.
  ***************************************************************************************
  *
  * Copyright (c) 2019-2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ***************************************************************************************
  @endverbatim

Matter ST67W6X_Lighting-App over WiFi – NUCLEO-U575ZI-Q + NUCLEO-67W61M1
========================================================================

Overview
--------

This project implements a Matter-compliant On/Off Lighting device using X-CUBE-MATTER.
It runs on the STM32U575ZI-Q MCU (NUCLEO-U575ZI-Q board) and uses the ST67W61 module
(NUCLEO-67W61M1) for both Wi-Fi and BLE communication, connected over SPI.

The device can be commissioned over BLE and connected to a Wi-Fi network, enabling
control through a Matter controller (e.g., the CHIP tool). OTA is not supported
in this version.

Key Features
------------

- Matter Lighting device (On/Off cluster)
- BLE commissioning using ST67W61
- Wi-Fi connectivity via ST67W61 over SPI
- UART-based debug logging at 921600 baud
- Compatible with standard Matter controllers

Requirements
------------

- NUCLEO-U575ZI-Q development board
- ST67W61 Wi-Fi module (NUCLEO-67W61M1)
- Flashed NCP firmware on ST67W61
- CHIP tool or other Matter controller
- STM32CubeIDE (latest version)

ST67W61 Firmware Flashing
-------------------------

Before running the application, the ST67W61 module must be flashed with the correct
NCP firmware.

IMPORTANT
1. These scripts are intended to be used with the NUCLEO-U575ZI-Q board and the X-NUCLEO-67W61M1 expansion board.
The NUCLEO-U575ZI-Q board must be connected to the PC via USB, and the X-NUCLEO-67W61M1 expansion board must be connected to the NUCLEO-U575ZI-Q board.
2. To avoid any issues, connect only the NUCLEO-U575ZI-Q host to which the X-NUCLEO-67W61M1 expansion board is connected.
3. The default STM32CubeProgrammer installation path is C:/Program Files/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin

Flashing Instructions:

1. Connect the NUCLEO-U575ZI-Q board (with the X-NUCLEO-67W61M1 expansion board plugged into it) to your PC using its UART interface.
2. Navigate to the following directory in your X-CUBE-MATTER package:
   Projects\ST67W6X_Utilities\Binaries
3. Run the provided batch file to flash the NCP firmware:
   NCP_update_mission_profile_t02.bat
4. Wait until the process completes. The ST67W61 is now ready to be used as a Wi-Fi + BLE NCP.

Build & Flash – NUCLEO-U575ZI-Q
-------------------------------

1. Open the project in STM32CubeIDE
2. Click "Project > Build All" to compile the firmware
3. Connect the board to your PC via USB
4. Use ST-LINK (integrated on the NUCLEO board) to flash the firmware:
   - Click "Run > Debug" or use the Flash icon
5. After flashing, reset the board or press the RESET button to start execution

Commissioning Procedure
-----------------------

1. Power on the device (NUCLEO-U575ZI-Q + NUCLEO-67W61M1)
2. The application will start in BLE commissioning mode
3. Use the CHIP tool (or equivalent) to commission the device using BLE + Wi-Fi:

   ./chip-tool pairing ble-wifi <node-id> <ssid> <password> <setup-pin-code> <discriminator>

4. After successful commissioning, the device connects to the Wi-Fi network and becomes operational.

Controlling the Device
----------------------

Once commissioned, you can control the on/off functionality using:

   ./chip-tool onoff on <node-id> 1
   ./chip-tool onoff off <node-id> 1

LED Behavior – NUCLEO-U575ZI-Q (LED2)
-------------------------------------

The On/Off state of the Matter lighting device is represented by the on-board **LED2** on the NUCLEO-U575ZI-Q.

- When the Matter node receives an **On** command, **LED2 turns ON**.
- When the Matter node receives an **Off** command, **LED2 turns OFF**.

This LED indicates the logical state of the light cluster.

User Button Behavior – NUCLEO-67W61M1
-------------------------------------

The USER button on the NUCLEO-67W61M1 provides the following functions:

- **Single press**: Triggers saving of the current configuration and Matter data to NVM (non-volatile memory).
- **Multiple rapid presses** (e.g., 2 presses within a short interval): Triggers a **factory reset** of the NUCLEO-67W61M1 and the NUCLEO-U575ZI-Q.

Use these features to manually manage the device state or reset it during testing or re-commissioning.


Debugging
---------

- Logs are available over UART at 921600 baud
- Configure your terminal software (e.g., PuTTY, Tera Term) with:
    - Baud rate: 921600
    - Data bits: 8
    - Parity: None
    - Stop bits: 1
- Logs will show BLE/Wi-Fi status, commissioning progress, and Matter events

Notes
-----

- The application does not support OTA updates in this version.
- BLE commissioning is handled entirely by the ST67W61 module.
- Wi-Fi credentials are configured during commissioning via the controller.
- Make sure the NUCLEO-67W61M1 is correctly connected over SPI and initialized by the STM32 firmware.

References
----------

- X-CUBE-MATTER – STMicroelectronics:
  https://www.st.com/en/embedded-software/x-cube-matter.html
- X-CUBE-MATTER Wiki:
  https://wiki.st.com/stm32mcu/wiki/Connectivity:Introduction_to_Matter

- X-CUBE-ST67W6X – STMicroelectronics:
  https://www.st.com/en/embedded-software/x-cube-st67w6x.html
- X-CUBE-ST67W6X Wiki:
  https://wiki.st.com/stm32mcu/wiki/Category:X-CUBE-ST67W61

- NUCLEO-U575ZI-Q Board:
  https://www.st.com/en/evaluation-tools/nucleo-u575zi-q.html
