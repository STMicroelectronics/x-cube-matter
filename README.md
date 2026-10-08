# X-CUBE-MATTER Software Expansion for STM32Cube

![tag](https://img.shields.io/badge/tag-XCM_V1.6.0-brightgreen.svg)
[![release note](https://img.shields.io/badge/release_note-view_html-gold.svg)](https://htmlpreview.github.io/?https://github.com/STMicroelectronics/x-cube-matter/blob/main/Release_Notes.html)
[![offer](https://img.shields.io/badge/stm32cube_mcu_offer-browse-orange.svg)](https://github.com/STMicroelectronics/STM32Cube_MCU_Overall_Offer)

## Overview

This repository provides X-CUBE-MATTER: an STMicroelectronics software expansion delivering reference Matter (Project Connected Home over IP) implementations and samples for STM32 devices. It includes end-device, bridge, and gateway examples targeting Thread, Wi-Fi, and Ethernet network interfaces.

## Source

This README is based on ST's Discover Matter documentation: https://wiki.st.com/stm32mcu/wiki/Connectivity:Introduction_to_Matter

## What is Matter

- Summary: Matter is an open, IP-based smart-home application protocol from the Connectivity Standards Alliance (CSA). It runs over IPv6, commonly using Thread, Wi-Fi, or Ethernet for operational networking, and Bluetooth LE for commissioning.
- Stack: Application (clusters/attributes), Transport (TCP/UDP; BTP for commissioning), Network (IPv6), Link/PHY (Thread/Wi-Fi/Ethernet).

## Key Concepts

- Device roles: End device (sensors, lights, locks), Bridge (expose non-Matter devices), Controller (smartphone/tablet used for commissioning), Thread border router (connects Thread to other IP networks).
- Commissioning: Bluetooth LE (BTP) is used for commissioning devices into a Matter Fabric.

## Supported STM32 platforms (examples)

- End-device candidates: `STM32WBA65RI` (STM32WBA65I-DK1), `STM32U575ZI` (NUCLEO-U575ZI-Q with X-NUCLEO-67W61M1 Wi-Fi/BLE module), `STM32WB5MMG` (legacy — note removal in some X-CUBE versions).
- RCP (Radio Co-Processor): `STM32WBA55CG` (NUCLEO-WBA55CG), `STM32WB55RG` (NUCLEO-WB55RG).
- Bridge / gateway platforms: `STM32H753ZI` (NUCLEO-H753ZI) for Ethernet-based bridge examples; STM32MP1 platforms for OpenThread Border Router (OTBR) gateway builds.

## Provided samples

- Matter end device samples: lighting, window-app, and other accessory examples for Thread, Wi-Fi, or Ethernet.
- Bridge sample: `Bridge-App` (NUCLEO-H753ZI) demonstrating bridged endpoints (simulated in example).
- Gateway / OTBR: STM32MP1-based OpenThread border router example using a NUCLEO RCP.

## Binaries & Folder layout

- Delivered binaries are included under `Projects/<board>/Applications/Matter/<App>/Binaries` in the X-CUBE-MATTER package.
- Example paths:
  - `X-CUBE-MATTER/Projects/STM32WBA65I-DK1/Applications/Matter/Window-App/Binaries`
  - `X-CUBE-MATTER/Projects/NUCLEO-H753ZI/Applications/Matter/Bridge-App/Binaries/STM32CubeIDE`

## Getting started (fast path)

1. Choose the network technology: Thread or Wi-Fi.
2. Pick a supported end-device or bridge platform.
3. Download X-CUBE-MATTER from ST: https://www.st.com/en/embedded-software/x-cube-matter.html
4. Program the delivered binary for your chosen target.
5. Commission the device with a Matter controller app (BLE commissioning) and validate in the Matter Fabric.

## Building from source (summary)

- Prerequisites: STM32CubeIDE or supported toolchain, X-CUBE-MATTER sources, any required OpenThread/NCP dependencies or NCP firmware for Wi-Fi.
- Steps: open target project in STM32CubeIDE (or your build system), ensure external dependencies are available, build the application (M4/M0 or single-core targets as applicable), and flash the binary.
- RCP/OTBR setup: pair an RCP (NUCLEO WB/WBA boards) with an STM32MP1 or host running OTBR via serial/USB per ST's How-To documentation.

## Commissioning & Testing

- Use a Matter-certified controller (mobile app or test harness) for commissioning.
- For Thread setups, ensure a Thread Border Router (OTBR) is available or use the STM32MP1 OTBR example.
- For Wi-Fi devices, follow board-specific NCP instructions for network setup.

## Notes & Caveats

- Platform support and sample availability may vary by X-CUBE-MATTER release (see Release Notes). For example, some STM32WB5MMG-based content was removed in later versions.
- X-CUBE-MATTER uses sources from the Project Connected Home over IP (connectedhomeip) open-source project; observe its license and compatibility requirements.

## References

- ST Discover Matter: https://wiki.st.com/stm32mcu/wiki/Connectivity:Introduction_to_Matter
- X-CUBE-MATTER product page: https://www.st.com/en/embedded-software/x-cube-matter.html
- Project Connected Home over IP (Matter): https://github.com/project-chip/connectedhomeip


## Feedback and contributions

We value and appreciate feedback and contributions from the community. Please refer to the [CONTRIBUTING.md](CONTRIBUTING.md) file for details on how to participate effectively.
