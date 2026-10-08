
##################################
#  Tools and scripts for Matter  #
##################################


==============================================================================
CreateMatterBin.py
==============================================================================
origin: STMicroelectronics

description: 
Create Matter binary file by assembling header + 1 or 2 binary files. 

note: 
Only -bin1 option is mandatory 
If the 2nd binary (ST67 binary for U5 or SecureApp for WBA6) is not updated, do not specify -bin2 option.
The script will use an empty binary2 in this case.
The output binary will use a default name if -o option is not used.

usage examples:
python ./CreateMatterBin.py --help

U5 example:
python.exe .\CreateMatterBin.py -bin1 c:\MATTER\path_to_U5_bin\sbsfu_app_enc_sign.bin -bin2 c:\MATTER\path_to_ST67_bin\st67w611m_mission_t02_v2.0.89.bin.ota -o my-firmware.bin

WBA6 example:
python.exe .\CreateMatterBin.py -bin1 c:\MATTER\path_to_NSAPP_bin\my-NSAPP.bin -o my-firmware.bin


==============================================================================
ota_image_tool.py
==============================================================================
origin: Project chip
can be found in connectedhomeip\src\app\ota_image_tool.py

note: 
The version of the script corresponds to the version of Matter (formerly Project CHIP) used for the X-Cube Matter.
The version can be found in the top release note, in root directory, of the X-Cube Matter.

description: 
Matter OTA (Over-the-air update) image utility.
This script can be used to: Create OTA image, Show OTA image info, Remove the OTA header from an image file or 
Change the specified values in the header.
 
note:
To work outside of CHIP environment, this script requires to use functions from chip.tlv
The following tree is required by the script. It comes from connectedhomeip\src\controller\python\chip\tlv
   [chip]
        __init__
        [tlv]
            __init__

usage examples:
python ./ota_image_tool.py --help
python ./ota_image_tool.py create -v <VENDOR_ID> -p <PRODUCT_ID> -vn <VERSION> -vs <VERSION_STRING> -da sha256 my-firmware.bin my-firmware.ota
python ./ota_image_tool.py create -v 0xDEAD -p 0xBEEF -vn 1 -vs "1.0" -da sha256 my-firmware.bin my-firmware.ota


==============================================================================
ST_ota_image_tool.py
==============================================================================
origin: STMicroelectronics

description: 
This script is an overlay of the script ota_image_tool.py
The <VENDOR_ID>, <PRODUCT_ID> and <VERSION> parameters are extracted from the specified CHIPProjectConfig.h file.
The <VERSION_STRING> has to be specified manually with -vs

note:
The script ota_image_tool.py and the [chip] directory are required to execute this script.

usage examples:
python ./ST_ota_image_tool.py --help
python ./ST_ota_image_tool.py -cc <full_path>/CHIPProjectConfig.h -vs "my-new-version-string" my-firmware.bin my-firmware.ota




