README - Generating the TFM Binary for the Matter Project
========================================================

This document describes the steps required to generate the TFM binary for the Matter project on the STM32WBA65I-DK1 platform.

**Note:** 
More information is available on the Matter wiki at: https://wiki.st.com/stm32mcu/wiki/Category:Matter

**Note:**  
The following instructions and examples are provided for a Windows environment. The process should also work on Linux, but commands and paths may need to be adapted accordingly. The prerequisites listed below are specific to the Windows setup used in these examples.

PREREQUISITES
-------------
- Windows PC
- Git Bash shell
- Working directory: C:\WBA6

1. INSTALL REQUIRED TOOLS
-------------------------
Follow the official Trusted Firmware-M documentation to install all necessary tools:
https://trustedfirmware-m.readthedocs.io/en/latest/getting_started/index.html

Note: CMake and Ninja are used as build generators.

2. CLONE THE TFM REPOSITORY
---------------------------
Open a Git Bash shell and run the following commands:

    mkdir WBA6
    cd WBA6
    git clone https://review.trustedfirmware.org/TF-M/trusted-firmware-m
    cd trusted-firmware-m
    git checkout 63bcfc10cc2

> **Note:** SHA1 `63bcfc10cc2` is the version tested by STMicroelectronics for the Matter application.

3. APPLY STMicroelectronics PATCHES FOR MATTER
----------------------------------------------
Return to the parent directory:

    cd ..

Unzip the `TFM-Matter-patch.zip` archive **above** the `/c/WBA6/trusted-firmware-m` directory.
> **Warning:** 4 files will be overwritten by this operation.

4. BUILD TFM FOR MATTER BINARIES
--------------------------------
From `/c/WBA6/`, run:

    cmake -S ./trusted-firmware-m -B ./build_s -GNinja -DTFM_PLATFORM=stm/stm32wba65i_dk -DTFM_TOOLCHAIN_FILE=/c/WBA6/trusted-firmware-m/toolchain_GNUARM.cmake -DCMAKE_BUILD_TYPE=Release -DTFM_ISOLATION_LEVEL=2 -DTFM_PROFILE=profile_large
    cmake --build ./build_s -- install

- The `build_s` directory will be created alongside `trusted-firmware-m`.
- The generated binaries are located in `/c/WBA6/build_s/api_ns/bin/`:
    - `tfm_s_fmw.bin`: main TFM binary (**to be renamed and signed**)
    - `tfm_s_otp.bin`: flash memory partition for NV OTP / PS / ITS (**to be used as is**)

5. IMPORT TFM-MATTER BINARIES INTO THE X-CUBE-Matter ECOSYSTEM
--------------------------------------------------------------
- Copy `tfm_s_otp.bin` to:
  `\Projects\STM32WBA65I-DK1\Applications\ROT_TFM\OEMiROT_Appli_TrustZone\Binary\`
- Copy `tfm_s_fmw.bin` to the same folder and rename it to `oemirot_tz_s_app.bin`

6. SIGN THE BINARY WITH TRUSTED PACKAGE CREATOR
-----------------------------------------------
- Open **STM32TrustedPackageCreator.exe** (included in STM32CubeProgrammer/bin, version >2.19.0 recommended).
- In the left menu, select the **Security** icon, then in the right panel, select the **"Image Gen"** tab.
- Select the following XML file: `OEMiROT_S_Code_Init_Image.xml`
  This file is located in the ROT_Provisioning directory corresponding to your application (for example: `Projects\STM32WBA65I-DK1\ROT_Provisioning_Lighting_TFM\OEMiROT\Images`).
- Click the **Generate Image** button.

The file `oemirot_tz_s_app_init_sign.bin` should then be generated in the Binary directory of your application.

> **Note:** For detailed instructions on using Trusted Package Creator, refer to the STM32CubeProgrammer documentation.

The files to be used for Matter provisioning are:
- `oemirot_tz_s_app_init_sign.bin`
- `tfm_s_otp.bin`

These files will be flashed into internal memory using the Matter provisioning scripts.