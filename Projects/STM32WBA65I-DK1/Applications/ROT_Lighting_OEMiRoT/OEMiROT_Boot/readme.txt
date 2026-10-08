## <b>OEMiROT_Boot Application Description</b>
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
  
This project provides an OEMiROT boot path for Matter.
Matter MCUboot configuration:
  - Primary and secondary slots are used.
  - The "overwrite" method (not "swap") is used to save 64 KB.
  - Secure and Non-Secure Data slots are not used.
The external loader is disabled (MCUBOOT_EXT_LOADER).

The OEMiROT boot path performs authenticity and integrity checks on the project firmware and data images.

OEMiRoT stands for OEM immutable (unchangeable) Root of Trust and acts as a first boot stage. OEMiRoT is an example based on the MCUboot and MbedTLS open-source software. OEMiRoT offers two services:

- The Secure Boot (root of trust service) is an immutable code, which is always executed after a system reset. It checks static protections (options bytes),
  activates runtime protections, and then verifies the authenticity and integrity of the user application code before every execution.
- The Secure Firmware Update application is an immutable code that detects new firmware image candidate. It checks its version (version downgrade prevention),
  authenticity, and integrity before installing it after decryption.

It relies on cryptography hardware peripherals for optimal performance (PKA, SAE, HASH, RNG).
This project is fully secure.

To simplify the development process, pre-build and post-build commands are integrated into the project.
The pre-build command prepares the OEMiROT_Boot scatter file according to the flash layout description.
The post-build command prepares the provisioning scripts and the application image
(firmware application managed by OEMiROT) configuration files in the
ROT_Provisioning_Lighting_OEMiRoT/OEMiROT folder, according to the flash
layout and OEMiROT configuration.

The maximum system clock frequency is configured at 100 MHz.

### <b>Keywords</b>

TrustZone, OEMiROT, Boot path, Root Of Trust, Security, mcuboot

### <b>Directory contents</b>

  - OEMiROT_Boot/Inc/boot_hal_cfg.h                    Platform configuration file for OEMiROT_Boot
  - OEMiROT_Boot/Inc/boot_hal_flowcontrol.h            Header file for flow control code in boot_hal.c
  - OEMiROT_Boot/Inc/boot_hal_hash_ref.h               Header file for hash reference code in boot_hal.c
  - OEMiROT_Boot/Inc/boot_hal_imagevalid.h             Header file for image validation code in boot_hal.c
  - OEMiROT_Boot/Inc/cmsis.h                           Header file for CMSIS
  - OEMiROT_Boot/Inc/flash_layout.h                    Flash mapping
  - OEMiROT_Boot/Inc/low_level_flash.h                 Header file for low_level_flash.c
  - OEMiROT_Boot/Inc/low_level_spi_flash.h             Header file for low_level_spi_flash.c
  - OEMiROT_Boot/Inc/low_level_rng.h                   Header file for low_level_rng.c
  - OEMiROT_Boot/Inc/low_level_security.h              Header file for low_level_security.c
  - OEMiROT_Boot/Inc/mbedtls_alt_config.h              Configuration file for Middlewares/ST/mbedtls_alt
  - OEMiROT_Boot/Inc/mbedtls_config.h                  MbedTLS configuration file
  - OEMiROT_Boot/Inc/mcuboot_config/mcuboot_config.h   Mcuboot configuration file
  - OEMiROT_Boot/Inc/mpu_armv8m_drv.h                  Header file for mpu_armv8m_drv.c
  - OEMiROT_Boot/Inc/oemirot_peripherals_def.h         Peripheral definitions
  - OEMiROT_Boot/Inc/region_defs.h                     RAM and FLASH regions definitions
  - OEMiROT_Boot/Inc/stm32_board.h                     Definitions for stm32wbaxx board
  - OEMiROT_Boot/Inc/stm32_hal.h                       Header file for wba specifics include
  - OEMiROT_Boot/Inc/stm32_ll.h                        Definitions for stm32wbaxx
  - OEMiROT_Boot/Inc/stm32wbaxx_hal_conf.h             HAL driver configuration file
  - OEMiROT_Boot/Inc/stm32wba55g_discovery_conf.h      STM32WBA55G Discovery board configuration file
  - OEMiROT_Boot/Inc/stm32wba55g_discovery_errno.h     STM32WBA55G Discovery board errors file
  - OEMiROT_Boot/Inc/stm32wba65i_discovery_conf.h      STM32WBA65I Discovery board configuration file
  - OEMiROT_Boot/Inc/stm32wba65i_discovery_errno.h     STM32WBA65I Discovery board errors file
  - OEMiROT_Boot/Inc/target_cfg.h                      Header file for target startup

  - OEMiROT_Boot/Src/bl2_nv_services.c                 Non Volatile services for OEMiROT_Boot
  - OEMiROT_Boot/Src/boot_hal.c                        Platform initialization
  - OEMiROT_Boot/Src/image_macros_to_preprocess_bl2.c  Images definitions to preprocess for bl2
  - OEMiROT_Boot/Src/keys_map.c                        keys indirection to access keys in PERSO area
  - OEMiROT_Boot/Src/low_level_com.c                   Uart low level interface
  - OEMiROT_Boot/Src/low_level_device.c                Flash Low level device configuration
  - OEMiROT_Boot/Src/low_level_flash.c                 Flash Low level interface
  - OEMiROT_Boot/Src/low_level_spi_device.c            External Flash Low level device configuration
  - OEMiROT_Boot/Src/low_level_spi_flash.c             External Flash Low level interface
  - OEMiROT_Boot/Src/low_level_rng.c                   RNG Low level interface
  - OEMiROT_Boot/Src/low_level_security.c              Security Low level services
  - OEMiROT_Boot/Src/mpu_armv8m_drv.c                  Mpu low level interface
  - OEMiROT_Boot/Src/startup_stm32wbaxx.c              Startup file in c
  - OEMiROT_Boot/Src/system_stm32wbaxx.c               System Init file
  - OEMiROT_Boot/Src/tick.c                            HAL Tick implementation

### <b>Hardware and Software environment</b>

  - This example runs on STM32WBA65I-DK1 devices with security enabled (TZEN=B4).
  - This example has been tested with an STMicroelectronics STM32WBA65I-DK1 (MB2130).
  - To get debug prints on your UART console, configure it with these parameters:
    Speed: 115200, Data: 8bits, Parity: None, stop bits: 1, Flow control: none.

### <b>How to use it?</b>

<u>Before compiling the project, you should first start the provisioning process</u>.

Before starting the provisioning process, select the application project to use
(application example or template) through the `oemirot_appli_path_project`
variable in `ROT_Provisioning_Lighting_OEMiRoT/env.bat` or `env.sh`.
Then start the provisioning process by running `provisioning.bat` (`.sh` on
Linux) from `ROT_Provisioning_Lighting_OEMiRoT/OEMiROT`, and follow its
instructions. Refer to the `ROT_Provisioning_Lighting_OEMiRoT/OEMiROT` readme
for more information on
the provisioning process for OEMiROT boot path or OEMiROT_OEMuROT boot path.

Refer to the OEMiROT_Appli readme for an example of an application booted
through the OEMiROT boot path.

For more details, refer to STM32WBA Wiki articles:

  - [STM32WBA security](https://wiki.st.com/stm32mcu/wiki/Category:STM32WBA).
  - [How to start with ROT on STM32WBA](https://wiki.st.com/stm32mcu/wiki/Category:How_to_start_with_RoT_on_WBA).

#### <b>Notes:</b>

By default, anti-tamper is enabled for internal tamper events only. It is
possible to change this configuration with the `OEMIROT_TAMPER_ENABLE` define
in `Inc\\boot_hal_cfg.h`.
External tamper is TAMP_IN4 (PC13, user button) on STM32WBA65I-DK1 board.

```
#define NO_TAMPER            (0)                   /*!< No tamper activated */
#define INTERNAL_TAMPER_ONLY (1)                   /*!< Only Internal tamper activated */
#define ALL_TAMPER           (2)                   /*!< Internal and External tamper activated */
#define OEMIROT_TAMPER_ENABLE INTERNAL_TAMPER_ONLY /*!< TAMPER configuration flag  */
```

If `OEMIROT_TAMPER_ENABLE` is changed to `ALL_TAMPER`, anti-tamper protection
is enabled using active tamper pins.
Moreover, no warning message about anti-tamper detection will be displayed if the RDP level is set to 2,
even with OEMIROT_DEV_MODE enabled.

### <b>Restrictions:</b>

For STM32WBA65I-DK1 devices, across all IDEs, the following limitation applies:

   - RDP level 0.5 not supported.

