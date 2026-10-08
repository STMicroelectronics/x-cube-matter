#!/bin/bash -
#=================================================================================================
# Managing HOST OS diversity : begin 
#=================================================================================================
OS=$(uname)

echo ${OS} | grep -i -e windows -e mingw >/dev/null
if [[ $? == 0 ]]; then
  echo "HOST OS : Windows detected"
  OS="Windows_NT"
elif [[ "$OS" == "Linux" ]]; then
  echo "HOST OS : Linux detected"
elif [[ "$OS" == "Darwin" ]]; then
  echo "HOST OS : MacOS detected"
else
  echo "!!!HOST OS not supported : >$OS<!!!"
  exit 1
fi

#=================================================================================================
# Managing HOST OS diversity : end 
#=================================================================================================
echo "SBSFU_UPDATE started"
# Get Absolute path to this script use "readlink" for linux/windows and "stat" for Mac OS
if [[ "$OS" == "Darwin" ]]; then
  SCRIPT=$(stat -f $0)
else
  SCRIPT=$(readlink -f $0)
fi
SCRIPT_PATH=`dirname $SCRIPT`
source ../../env.sh
connect_no_reset="-c port=SWD mode=UR"
connect="-c port=SWD mode=UR --hardRst"
slot0=0xC01A000
slot1=0x0
slot2=0xC100000
slot3=0x0
slot4=0x0
slot5=0x0
slot6=0x0
slot7=0x0
boot=0xC004000
loader=0x0
cfg_loader=0
app_image_number=1
s_data_image_number=0
ns_data_image_number=0
if [ $app_image_number == 2 ]; then
echo "Write SBSFU_Appli Secure"
"$stm32programmercli" $connect -d $SCRIPT_PATH/../../SBSFU_Appli/Binary/sbsfu_s_app_init.bin $slot0 -v
ret=$?
if [ $ret != 0 ]; then
  if [ "$1" != "AUTO" ]; then read -p "SBSFU_UPDATE script failed, press a key" -n1 -s; fi
  exit 1
fi
echo "SBSFU_Appli Secure Written"
echo "Write SBSFU_Appli NonSecure"
"$stm32programmercli" $connect -d $SCRIPT_PATH/../../SBSFU_Appli/Binary/sbsfu_ns_app_init.bin $slot1 -v
ret=$?
if [ $ret != 0 ]; then
  if [ "$1" != "AUTO" ]; then read -p "SBSFU_UPDATE script failed, press a key" -n1 -s; fi
  exit 1
fi
echo "SBSFU_Appli NonSecure Written"
fi
if [ $app_image_number == 1 ]; then
echo "Write SBSFU_Appli"
"$stm32programmercli" $connect -d $SCRIPT_PATH/../../SBSFU_Appli/Binary/sbsfu_app_init.bin $slot0 -v
ret=$?
if [ $ret != 0 ]; then
  if [ "$1" != "AUTO" ]; then read -p "SBSFU_UPDATE script failed, press a key" -n1 -s; fi
  exit 1
fi
echo "SBSFU_Appli Written"
fi
if [ $s_data_image_number == 1 ]; then
echo "Write SBSFU_Appli Secure Data"
if [ ! -e $SCRIPT_PATH/../../SBSFU_Appli/Binary/sbsfu_s_data_init.bin ]; then
    if [ "$1" != "AUTO" ]; then read -p "Error : sbsfu_s_data_init.bin does not exist! Run dataimg.bat script to generate it" -n1 -s; fi
    exit 1
fi
"$stm32programmercli" $connect -d $SCRIPT_PATH/../../SBSFU_Appli/Binary/sbsfu_s_data_init.bin $slot4 -v
ret=$?
if [ $ret != 0 ]; then
  if [ "$1" != "AUTO" ]; then read -p "SBSFU_UPDATE script failed, press a key" -n1 -s; fi
  exit 1
fi
echo "TFM_Appli Secure Data Written"
fi
if [ $ns_data_image_number == 1 ]; then
echo "Write SBSFU_Appli NonSecure Data"
if [ ! -e $SCRIPT_PATH/../../SBSFU_Appli/Binary/sbsfu_ns_data_init.bin ]; then
    if [ "$1" != "AUTO" ]; then read -p "Error : sbsfu_ns_data_init.bin does not exist! Run dataimg.bat script to generate it" -n1 -s; fi
    exit 1
fi
"$stm32programmercli" $connect -d $SCRIPT_PATH/../../SBSFU_Appli/Binary/sbsfu_ns_data_init.bin $slot5 -v
ret=$?
if [ $ret != 0 ]; then
  if [ "$1" != "AUTO" ]; then read -p "SBSFU_UPDATE script failed, press a key" -n1 -s; fi
  exit 1
fi
echo "SBSFU NonSecure Data Written"
fi

# write loader if config loader is active
if [ $cfg_loader == 1 ]; then
echo "Write SBSFU_Loader"
"$stm32programmercli" $connect -d $SCRIPT_PATH/../../SBSFU_Loader/Binary/loader.bin $loader -v
ret=$?
if [ $ret != 0 ]; then
  if [ "$1" != "AUTO" ]; then read -p "SBSFU_UPDATE script failed, press a key" -n1 -s; fi
  exit 1
fi
echo "SBSFU_Loader Written"
fi
echo "Write SBSFU_Boot"
"$stm32programmercli" $connect -d $SCRIPT_PATH/Release/ST67W6X_OEMiROT_Boot_STM_Prov.bin $boot -v
ret=$?
if [ $ret != 0 ]; then
  #if [ "$1" != "AUTO" ]; then read -p "SBSFU_UPDATE script failed, press a key" -n1 -s; fi
  exit 1
fi
echo "SBSFU_Boot Written"
#if [ "$1" != "AUTO" ]; then read -p "SBSFU_UPDATE script Done, press a key" -n1 -s; fi
exit 0
