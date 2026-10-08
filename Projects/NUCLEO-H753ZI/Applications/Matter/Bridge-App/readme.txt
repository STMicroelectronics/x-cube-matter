****
  @page Bridge-App
  @verbatim
  ***************************************************************************************
  * @file    Projects\NUCLEO-H753ZI\Applications\Matter\Bridge-App\readme.txt
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

Matter Bridge-App over Ethernet – NUCLEO-H753ZI
===============================================

Overview
--------

This application provides an example of a Matter Bridge running on the
NUCLEO-H753ZI board with Ethernet connectivity.
This prototype application demonstrates dynamic endpoints with device
commissioning and cluster control.
It adds non-Matter devices as endpoints on a bridge that acts as a Matter
device.
In this example, six light devices supporting the On/Off cluster are added as
endpoints.

Key Features
------------

- Matter Bridge device (with On/Off cluster exposed as dynamic endpoints)
- Ethernet connectivity
- UART-based debug logging at 115200 baud
- Compatible with standard Matter controllers

Requirements
------------

- NUCLEO-H753ZI development board
- CHIP tool or other Matter controller
- STM32CubeIDE (latest version)

Build & Flash – NUCLEO-H753ZI
-----------------------------

1. Open the project in STM32CubeIDE
2. Click "Project > Build All" to compile the firmware
3. Connect the board to your PC via USB
4. Use ST-LINK (integrated on the NUCLEO board) to flash the firmware:
   - Click "Run > Debug" or use the Flash icon
5. After flashing, reset the board or press the RESET button to start execution

Commissioning Procedure
-----------------------

1. Connect the device (NUCLEO-H753ZI) to your network through an Ethernet cable
2. Power on the device
3. Use the CHIP tool (or equivalent) to commission the device:
Commissioning the bridge with setup PIN code:
   ./chip-tool pairing onnetwork {node_id} {pin_code}
Commissioning the bridge with long discriminator:
   ./chip-tool pairing onnetwork-long {node_id} {pin_code} {discriminator}
with:
{node_id}      : user-defined ID of node being commissioned
{pin_code}     : device-specific setup PIN code (default value: "20202021")
{discriminator}: device-specific setup discriminator code (default value: "3840")

4. After successful commissioning, the device is operational.

Controlling the endpoints
-------------------------

The bridge is configured to support a maximum of 8 devices and contains
6 pre-initialized virtual Light On/Off devices (also called bridged devices).
The endpoint identifier `{endpoint_id}` ranges from 3 to 8 for Light 1 to 6.
Once commissioned, you can control the bridge and the On/Off endpoints:

   ./chip-tool onoff on {node_id} {endpoint_id}
   ./chip-tool onoff off {node_id} {endpoint_id}

Using the terminal (New Line Transmit set to: CR+LF), several commands are
also available to add, remove, and change bridged device status.

LED Behavior – NUCLEO-H753ZI (LED1)
-----------------------------------

The On/Off state of the Light 1 bridged device is represented by the on-board
**LED1** on the NUCLEO-H753ZI.

- When the Matter node receives an **On** command for the Light 1 bridged device, **LED1 turns ON**.
- When the Matter node receives an **Off** command for the Light 1 bridged device, **LED1 turns OFF**.
- A frame is also sent using `hlpuart1`: `Light{n}:{status}`, where `{n}` is 1
   to 6 and `{status}` is `ON` or `OFF`.

User Button Behavior – NUCLEO-H753ZI
-------------------------------------

The USER button on the NUCLEO-H753ZI provides the following functions:

- **Single press**: Triggers saving of the current configuration and Matter data to NVM (non-volatile memory) (same as CLI command: `nvm save`).
- **Long press** (for 10 seconds): Triggers a **factory reset** of the NUCLEO-H753ZI (same as CLI command: `nvm reset`).

Use these features to manually manage the device state or reset it during testing or re-commissioning.

Debugging
---------

- Logs are available over UART at 115200 baud
- Configure your terminal software (e.g., PuTTY, Tera Term) with:
    - Baud rate   : 115200
    - Data bits   : 8
    - Parity      : None
    - Stop bits   : 1
    - Flow control: None
    - New Line Receive : AUTO
    - New Line Transmit: CR+LF
- Logs will show Ethernet status, commissioning progress, and Matter events

References
----------

- X-CUBE-MATTER – STMicroelectronics:
  https://www.st.com/en/embedded-software/x-cube-matter.html
- X-CUBE-MATTER Wiki:
   https://wiki.st.com/stm32mcu/wiki/Connectivity:Introduction_to_Matter

- NUCLEO-H753ZI Board:
  https://www.st.com/en/evaluation-tools/nucleo-h753zi.html
