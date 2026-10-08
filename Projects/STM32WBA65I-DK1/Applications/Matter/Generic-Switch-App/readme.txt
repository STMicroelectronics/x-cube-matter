****
  @page generic_switch_App
  @verbatim
  ******************************************************************************
  * @file    Matter/generic_switch_App
  * @author  MCD Application Team
  * @brief   This file lists the modifications made by STMicroelectronics to
  *          Matter for integration with the STM32Cube solution.
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



The generic_switch_App example is based on Matter and behaves as a Matter
accessory communicating over an 802.15.4 Thread network.
It can be commissioned into an existing Matter fabric and can interact with
other devices within this fabric.
The STM32WBA65I-DK1 board running the generic-switch-app application supports
BLE and OpenThread activity at the same time.

@par Keywords

THREAD,BLE,Matter

@par Directory contents


  Uses the Matter SDK.


@par Hardware and Software environment

  - This example has been tested with an STMicroelectronics STM32WBA65I-DK1 board.

@par How to use it?


The libraries used for BLE and OpenThread are provided as part of the project.
Refer to the release notes to identify the STM32CubeIDE and
STM32CubeProgrammer versions to use.


Minimum requirements for the demo:
- 1 STM32WBA65I-DK1 with generic-switch-App firmware.
- 1 OTBR (Raspberry Pi or MP135 + Nucleo RCP), or any Matter-supported ecosystem.
- 1 Smartphone (Android) with the "CHIPTool" mobile application, or chiptool on RPi, or an ecosystem application.


In order to make the program work, you must do the following:
 - Connect the STM32WBA65I-Discovery board to your PC
 - Open STM32CubeIDE
 - Rebuild all files and load your image into target memory
 - Run the example

To get traces in real time, you can connect a HyperTerminal to the STLink Virtual Com Port.

 For traces, the UART must be configured as follows:
    - BaudRate = 115200 baud
    - Word Length = 8 Bits
    - Stop Bit = 1 bit
    - Parity = none
    - Flow control = none

**** START DEMO ****
Follow the instructions defined in https://wiki.st.com/stm32mcu/wiki/Connectivity:Matter_test_and_demonstrate

On the first boot, the end device must be commissioned (BLE, then Thread).
On subsequent boots, only Thread is needed.

**** LCD SUMMARY ****
- No LCD display in low power mode.

**** LED SUMMARY ****
- No LED management


****  BUTTON SUMMARY ****
Joystick Mapping:

- Joystick DOWN:
  Save persistent data in non-volatile memory before resetting the board or removing its power supply.
- Joystick SELECT:
  Trigger a factory reset.
- Joystick LEFT:
  Trigger a short switch release.
- Joystick LEFT long press (3s):
  Trigger a long switch press.
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */





