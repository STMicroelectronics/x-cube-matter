****
  @page Lighting_App
  @verbatim
  ******************************************************************************
  * @file    Matter/Lighting_App
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



The Lighting_App example is based on Matter and behaves as a Matter
accessory communicating over an 802.15.4 Thread network.
It can be commissioned into an existing Matter fabric and can interact with
other devices within this fabric.
The STM32WBA65I-DK1 board running the lighting-app application supports BLE
and OpenThread activity at the same time.

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
- 1 STM32WBA65I-DK1 board with Lighting-App firmware.
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
LCD Mapping :
 - The LCD screen displays "BLE connected" when BLE rendezvous has started.
 - The LCD screen displays "Network Joined" when the board has joined a Thread network.
 - The LCD screen displays "LED ON" + the light level (value between 0 and 255)
   when using the "LIGHT ON/OFF & LEVEL CLUSTER" and pressing "On", and erases
   this line when pressing "Off" on the Android phone.
 - The LCD screen displays "Fabric Created" if commissioning succeeds,
   "Fabric Failed" if commissioning fails, and "Fabric Found" if credentials
   from non-volatile memory (NVM) are found.
**** LED SUMMARY ****
- When commissioned, the user can control the green LED (ON or OFF) as needed.


****  BUTTON SUMMARY ****
Joystick Mapping:

- Joystick DOWN:
  Save persistent data in non-volatile memory before resetting the board or removing its power supply.
- Joystick SELECT:
  Press the joystick to trigger a factory reset.
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
 


 
	   
