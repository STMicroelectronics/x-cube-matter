---
pagetitle: Release Notes for ST67W611M Network Coprocessor utilities
lang: en
header-includes: <link rel="icon" type="image/x-icon" href="../../_htmresc/favicon.png" />
---

::: {.row}
::: {.col-sm-12 .col-lg-4}

<center>
# Release Notes for
# <mark>ST67W611M Network Coprocessor utilities</mark>
Copyright &copy; 2024 STMicroelectronics\


[![ST logo](../../_htmresc/st_logo_2020.png)](https://www.st.com){.logo}
</center>

# Purpose

This release covers the delivery of __ST67W611M__ Network Coprocessor utilities.

| Directory                              | Description
| -------------                          | -----------
| [Binaries](Binaries/README.md)         | Contains the binaries to flash the Network Coprocessor
| [FOTA](FOTA/README.md)                 | Contains the script and resources for the Firmware Upgrade Over-The-Air with HTTP Server
| [Littlefs](Littlefs/README.md)         | Contains the Littlefs image, certificates and scripts generation for the Network Coprocessor

Here is the list of the supported binaries available in Binaries/NCP_Binaries directory:

| ST67W611M binary                        | Description
| -----------------------------------     | -----------
| st67w611m_boot2_v8.1.9.bin              | Bootrom of the chip, according to the partition table, starts the latest firmware
| st67w611m_mfg_v2.0.89.bin               | Manufacturing test solution includes testing of RF and other modules
| st67w611m_mission_t01_v2.0.89.bin       | Network Coprocessor includes BLE, Wi-Fi, TCP/IP features managed by AT commands over SPI
| st67w611m_mission_t02_v2.0.89.bin       | Network Coprocessor includes BLE and Wi-Fi features managed by AT commands over SPI. TCP/IP feature must be defined on Host
| partition.bin                           | Partition table image containing all memory region addresses
| st67w611m_mfg_v2.0.89.bin.ota           | Manufacturing test image for Firmware Upgrade Over-The-Air
| st67w611m_mission_t01_v2.0.89.bin.ota   | Network Coprocessor t01 image for Firmware Upgrade Over-The-Air
| st67w611m_mission_t02_v2.0.89.bin.ota   | Network Coprocessor t02 image for Firmware Upgrade Over-The-Air
| st67w611m_mfg_v2.0.89.xz.ota            | Manufacturing test compressed image for Firmware Upgrade Over-The-Air
| st67w611m_mission_t01_v2.0.89.xz.ota    | Network Coprocessor compressed t01 image for Firmware Upgrade Over-The-Air
| st67w611m_mission_t02_v2.0.89.xz.ota    | Network Coprocessor compressed t02 image for Firmware Upgrade Over-The-Air

Here is the list of the supported binaries available in Binaries/NUCLEO-U575ZI-Q_Binaries directory:

| STM32 Host binary                       | Description
| -----------------------------------     | -----------
| Bootloader.bin                          | Link ST-Link and X-NUCLEO-67W61M1 UARTs and switch the ST67W611M in Boot mode to proceed at the flash update
| UART_bypass.bin                         | Link ST-Link and X-NUCLEO-67W61M1 UARTs to execute the Manufacturing test over STM32 UART link (in using the st67w611m_mfg_*.bin)
| ST67W6X_CLI.bin                         | Command line interface Host project to test the X-NUCLEO-67W61M1 Wi-Fi solution based on Network Coprocessor (in using the st67w611m_mission_t01_*.bin)
| ST67W6X_CLI_LWIP.bin                    | Command line interface Host project to test the X-NUCLEO-67W61M1 Wi-Fi solution based on LwIP on host (in using the st67w611m_mission_t02_*.bin)
| ST67W6X_FOTA.bin                        | Host project to test the X-NUCLEO-67W61M1 Firmware upgrade over Wi-Fi (in using the st67w611m_mission_t01_*.bin)

Here is the list of the supported files available in Littlefs directory:

| littlefs.bin                            | File system image containing some predefined certificates for security features

:::

::: {.col-sm-12 .col-lg-8}
# Update History

::: {.collapse}
<input type="checkbox" id="collapse-section02" checked aria-hidden="true">
<label for="collapse-section02" aria-hidden="false">__V1.1.0 / 26-September-2025__</label>
<div>

## Main Changes

- ST67W611M Binaries updated to version 2.0.89
- Add of new ST67W611M binaries and scripts for T02 architecture (LwIP on host)
- ID 211259: Add ST67W6X_FOTA binary and FOTA HTTP server example to exercise the feature
- ID 211264: Replace WMIC by powershell command in NCP_update Windows scripts
- ID 210737: Improve python scripts provided for FOTA

## Contents

- FOTA header generation and HTTP server python scripts
- ST67W611M binaries for Mission and Manufacturing modes with scripts to flash them over host board
- LittleFS file system support with scripts to generate image of certificates

<small>The components flagged by "[]{.icon-st-update}" have changed since the
previous release. "[]{.icon-st-add}" are new.</small>

__ST67W611M Binary Table__:

| ST67W611M binaries                      | Version                     | SHA256 Signature
| -----------------------------------     | --------------------------- | ----------------
| st67w611m_boot2_v8.1.9.bin              | V8.1.9[]{.icon-st-update}   | cf17800b765a1fad50fb338e2eed14240bf728831cb7426e97aa858703227f99
| st67w611m_mfg_v2.0.89.bin               | V2.0.89[]{.icon-st-update}  | 5856e144c14998bb20ff0b83cbc95eef0a0673090b1ff464f3d9f7bdbcf6c080
| st67w611m_mission_t01_v2.0.89.bin       | V2.0.89[]{.icon-st-update}  | bbd64876cda506786d925e398d257445f7c1e59ff3a5ef59f083196d83c3ec33
| st67w611m_mission_t02_v2.0.89.bin       | V2.0.89[]{.icon-st-add}     | a79717f51174b4d0d6b93598400d959e28dd644346794e24b8dd35405597934d
| partition.bin                           | V2.0.89[]{.icon-st-update}  | 3893b11c48ee01669b1867743ca3297bb7e0511f4167c133095f8454c2313d72
| st67w611m_mfg_v2.0.89.bin.ota           | V2.0.89[]{.icon-st-update}  | 5a7cfdf26c61b95ea018016341db2e4cd405eab6bbfcf23e9d8e12ebb5d0df40
| st67w611m_mission_t01_v2.0.89.bin.ota   | V2.0.89[]{.icon-st-update}  | 475b75ffd21b9a6191071c8cb2bac8897bd8ae1668afb6fec146105031924f2d
| st67w611m_mission_t02_v2.0.89.bin.ota   | V2.0.89[]{.icon-st-add}     | f3a7b307be53cec5ce678ac735c3b9de5df2f26b616ef3cdcaca1c10589ffeb4
| st67w611m_mfg_v2.0.89.xz.ota            | V2.0.89[]{.icon-st-update}  | 5233d714d053e4b856086b3b115e56c9ad686effb15fdbb6567294187ef4992c
| st67w611m_mission_t01_v2.0.89.xz.ota    | V2.0.89[]{.icon-st-update}  | fc6eba97620ff4acc9b96e9619003332d27b400bf0ccb6af06dadaa9af4958a2
| st67w611m_mission_t02_v2.0.89.xz.ota    | V2.0.89[]{.icon-st-add}     | 926157d1e1c1196a262ed946ca16662d557d9d37ba1c5c6a6b6a2727ef7e652b

__NUCLEO-H7S3L8 Host Binary Table__:

| STM32 Host binaries                     | Version                     | SHA256 Signature
| -----------------------------------     | --------------------------- | ----------------
| Bootloader.bin                          | V1.0.0                      | c8793aea8fc0a6e110cd37b641b38b1b5f4c440cb5b3feb181c1d063ab0b2042
| UART_bypass.bin                         | V1.0.0                      | 44037d9935e7c7c6228a8577ae910bcb376ebfe138e4bef17fa12a724b1a4317
| ST67W6X_CLI_Appli.bin                   | V1.1.0[]{.icon-st-update}   | b381e375fdc69eb6a7b02193e356a691c422516b0c3d34f94d0f888fd93a70d3
| ST67W6X_CLI_Boot.bin                    | V1.0.0                      | ae90139628756eb4a78bf7347fe85073edc966a4bf7a25489363fa024cd9726a
| ST67W6X_CLI_LWIP_Appli.bin              | V1.1.0[]{.icon-st-add}      | 2fd58756b471669c2f8514132064a8fd38a2aa1a8a83c5bdd44f835a740a33ec
| ST67W6X_CLI_LWIP_Boot.bin               | V1.1.0[]{.icon-st-add}      | b4dd6e2eb1c6afeda9a626fae7ac8a9c8b761df51d20e326ac0ba38828a29818

__NUCLEO-H563ZI Host Binary Table__:

| STM32 Host binaries                     | Version                     | SHA256 Signature
| -----------------------------------     | --------------------------- | ----------------
| Bootloader.bin                          | V1.0.0                      | 3b1684904bc7a431b1923806feabbddebe5797a297728e473dd7a56bb148318f
| UART_bypass.bin                         | V1.0.0                      | e1d938b1d4ca76f100db3d73ca40955de0b61ea0eb3c3d2f4a3bc7946a35a486
| ST67W6X_CLI.bin                         | V1.1.0[]{.icon-st-update}   | ab9e5565a09aad4dea70e9b8c275aa6ff526ba4ab008c37714d030b9d94aa527
| ST67W6X_CLI_LWIP.bin                    | V1.1.0[]{.icon-st-add}      | e4c7010192455e17cc4a5a462da0d9a5d75ffa354e4e85c570dcafb905a01f16

__NUCLEO-N657ZI-Q Host Binary Table__:

| STM32 Host binaries                     | Version                     | SHA256 Signature
| -----------------------------------     | --------------------------- | ----------------
| Bootloader.bin                          | V1.1.0[]{.icon-st-update}   | f31b19149b3ca25f1b2ae53397fc2b33763c8f4e0784ebad4a02b013ffd66df1
| UART_bypass.bin                         | V1.1.0[]{.icon-st-update}   | d38b2a7e50b0728c19222e6a18d54f22b70f999df98d9ff27cffee0dd98f80f9
| ST67W6X_CLI_FSBL.bin                    | V1.1.0[]{.icon-st-update}   | bf2a240886cd75b3f9ef03a27a31337617314c9e606937bfa7ffacc2b39bb03e

__NUCLEO-U575ZI-Q Host Binary Table__:

| STM32 Host binaries                     | Version                     | SHA256 Signature
| -----------------------------------     | --------------------------- | ----------------
| Bootloader.bin                          | V1.0.0                      | 93020c8364896c02fd4881f328287a048db143f2f3ce80c9e83abc909fd71170
| UART_bypass.bin                         | V1.0.0                      | e63eeccc58b0f427c1c950e378774435c865a29c93f029491cc52ec4a3563ad5
| ST67W6X_CLI.bin                         | V1.1.0[]{.icon-st-update}   | a66e5a3ec2fb3c3ff53e00a81505e8846af94036fd8ad5af1724039739f78b1a
| ST67W6X_CLI_LWIP.bin                    | V1.1.0[]{.icon-st-add}      | 4235c1d462ce2bed6cb2cc46c6365ee22389fd1a51b40caed4cfe7005a06bb9e
| ST67W6X_FOTA.bin                        | V1.1.0[]{.icon-st-add}      | adc5ef7b4ef899f175d9ed933ecabcc7ef4eb3888a727b97f3ce82c1fe56e720

__Littlefs Binary Table__:

| Littlefs binary                         | Version                     | SHA256 Signature
| -----------------------------------     | --------------------------- | ----------------
| littlefs.bin                            | V1.1.0[]{.icon-st-update}   | ad4590959d7f002dd51f75d194dde821e3d6a7cff4a927f6128d1ec87c6a9924

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section01" aria-hidden="true">
<label for="collapse-section01" aria-hidden="false">__V1.0.0 / 28-May-2025__</label>
<div>

## Main Changes

- __First official release__

## Contents

- FOTA header generation and HTTP server python scripts
- ST67W611M binaries for Mission and Manufacturing modes with scripts to flash them over host board
- LittleFS file system support with scripts to generate image of certificates

<small>The components flagged by "[]{.icon-st-update}" have changed since the
previous release. "[]{.icon-st-add}" are new.</small>

__ST67W611M Binary Table__:

| ST67W611M binaries                      | Version                     | SHA256 Signature
| -----------------------------------     | --------------------------- | ----------------
| st67w611m_boot2_v8.1.9.bin              | V8.1.9                      | ffad5f13fe8452e34a5a19e47cf73a0f9ba01f6ec832c608496533a70ee74566
| st67w611m_mfg_v2.0.75.bin               | V2.0.75                     | 96aae4dee08a5b2ada4ca5f970b8b9526d1f067eebccdb489ba8030df61a964b
| st67w611m_mission_t01_v2.0.75.bin       | V2.0.75                     | e1e35948f1a1c3d54402a1b1d59a819866cbcbbad03813f3f9b9d7dc825999fe
| partition.bin                           | V2.0.75                     | 8e8436e83650f5f1d1ff06ff5cb0bfd61730cafb66c75e025dc7276a9bf45c5f
| st67w611m_mfg_v2.0.75.bin.ota           | V2.0.75                     | 337f7197232a2840129f600c6bc9d5a596a48543c41cd28f6f99f7125ce182a1
| st67w611m_mission_t01_v2.0.75.bin.ota   | V2.0.75                     | 5cd3b34684009c65c7b4b96bc7f55c437ac7cacc9eac171d39c9bb94eb65029b
| st67w611m_mfg_v2.0.75.xz.ota            | V2.0.75                     | 920361ec1928c566841431de14d1466b0069f5fcb49236972d79748cd6890400
| st67w611m_mission_t01_v2.0.75.xz.ota    | V2.0.75                     | 9e39d9328688bdb9eacc47d1f910b13881a897b645c35dae61774390d715bb43

__NUCLEO-H7S3L8 Host Binary Table__:

| STM32 Host binaries                     | Version                     | SHA256 Signature
| -----------------------------------     | --------------------------- | ----------------
| Bootloader.bin                          | V1.0.0                      | c8793aea8fc0a6e110cd37b641b38b1b5f4c440cb5b3feb181c1d063ab0b2042
| UART_bypass.bin                         | V1.0.0                      | 44037d9935e7c7c6228a8577ae910bcb376ebfe138e4bef17fa12a724b1a4317
| ST67W6X_CLI_Appli.bin                   | V1.0.0                      | cc2a93de00ec775f3c08c35889f1c33fc3f61a3ff869f44de95c7b970ddaf6a1
| ST67W6X_CLI_Boot.bin                    | V1.0.0                      | ae90139628756eb4a78bf7347fe85073edc966a4bf7a25489363fa024cd9726a

__NUCLEO-H563ZI Host Binary Table__:

| STM32 Host binaries                     | Version                     | SHA256 Signature
| -----------------------------------     | --------------------------- | ----------------
| Bootloader.bin                          | V1.0.0                      | 3b1684904bc7a431b1923806feabbddebe5797a297728e473dd7a56bb148318f
| UART_bypass.bin                         | V1.0.0                      | e1d938b1d4ca76f100db3d73ca40955de0b61ea0eb3c3d2f4a3bc7946a35a486
| ST67W6X_CLI.bin                         | V1.0.0                      | 59b13e819a5ee95817ff537c735f4ab4da6cd3a68ead45e7a752ee6a057aeb06

__NUCLEO-N657ZI-Q Host Binary Table__:

| STM32 Host binaries                     | Version                     | SHA256 Signature
| -----------------------------------     | --------------------------- | ----------------
| Bootloader.bin                          | V1.0.0                      | 9b6734ed4ea4c8952f12963136d77b903cee92240b6b065c641f2aad1b21fee5
| UART_bypass.bin                         | V1.0.0                      | 1674f38a09f7ff31210d6c9cbd4209549f425c704586e955f160a6fafc10bfa3
| ST67W6X_CLI_FSBL.bin                    | V1.0.0                      | a8919c87614859a3ce7745900a667c83fa7936a07689139338e9b2e1a755bedd

__NUCLEO-U575ZI-Q Host Binary Table__:

| STM32 Host binaries                     | Version                     | SHA256 Signature
| -----------------------------------     | --------------------------- | ----------------
| Bootloader.bin                          | V1.0.0                      | 93020c8364896c02fd4881f328287a048db143f2f3ce80c9e83abc909fd71170
| UART_bypass.bin                         | V1.0.0                      | e63eeccc58b0f427c1c950e378774435c865a29c93f029491cc52ec4a3563ad5
| ST67W6X_CLI.bin                         | V1.0.0                      | 170d9d1145a0d17431bdace1f863f44b9c2a629a6a0261f067aaaa1a92c43dcb

__Littlefs Binary Table__:

| Littlefs binary                         | Version                     | SHA256 Signature
| -----------------------------------     | --------------------------- | ----------------
| littlefs.bin                            | V1.0.0                      | 5d08275cf5614b7d81fe7fafe287d21f6423ab84e10c0ed229efb37ce8959b87

</div>
:::

:::
:::

<footer class="sticky">
::: {.columns}
::: {.column width="95%"}
For complete documentation on STM32,
visit: [www.st.com/stm32](http://www.st.com/stm32)

*This release note uses up to date web standards and, for this reason, should not be opened with Internet Explorer but preferably with popular browsers such as Google Chrome, Mozilla Firefox, Opera or Microsoft Edge.*
:::
::: {.column width="5%"}
<abbr title="Based on template cx566953 version 2.0">Info</abbr>
:::
:::
</footer>
