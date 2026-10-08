import os
import ctypes
import time
import common
from common import RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, RESET

def Provisioning(provision_mode, header, port):
    """
    Manages the provisioning process.

    Args:
        provision_mode (int): The provisioning mode. 0 for TEST, 1 for Production.
        header (str): The header text to display in messages.
        port (str): The COM port to open.

    Returns:
        tuple: A tuple containing an error code and an optional error message.
    """

    ReturnedValues = {
        0x0000 : f"{GREEN}{header}Provisioning Done{RESET}",
        0x0040 : f"{RED}{header}Invalid arguments are passed to device SDK{RESET}",
        0x0042 : f"{RED}{header}Device ID length is larger than 64{RESET}",
        0x0043 : f"{RED}{header}Device SDK failed to allocate memory{RESET}",
        0x0044 : f"{RED}{header}PAI length in the message is larger than 600{RESET}",
        0x0045 : f"{RED}{header}DAC length in the message is larger than 600{RESET}",
        0x0046 : f"{RED}{header}Provision mode length in the message is larger than 1{RESET}",
        0x0047 : f"{RED}{header}Device SDK does not recognize the message send by proxy SDK{RESET}",
        0x0051 : f"{RED}{header}Random number generation failed due to HAL_ERROR{RESET}",
        0x0052 : f"{RED}{header}Random number generation failed due to HAL_BUSY{RESET}",
        0x0053 : f"{RED}{header}Random number generation failed due to HAL_TIMEOUT{RESET}",
        0x0061 : f"{RED}{header}EC point computation failed due to HAL_ERROR{RESET}",
        0x0062 : f"{RED}{header}EC point computation failed due to HAL_BUSY{RESET}",
        0x0063 : f"{RED}{header}EC point computation failed due to HAL_TIMEOUT{RESET}",
        0x0071 : f"{RED}{header}EC signature computation failed due to HAL_ERROR{RESET}",
        0x0072 : f"{RED}{header}EC signature computation failed due to HAL_BUSY{RESET}",
        0x0073 : f"{RED}{header}EC signature computation failed due to HAL_TIMEOUT{RESET}",
        0x0081 : f"{RED}{header}Failed to receive message due to HAL_ERROR{RESET}",
        0x0082 : f"{RED}{header}Failed to receive message due to HAL_BUSY{RESET}",
        0x0083 : f"{RED}{header}Failed to receive message due to HAL_TIMEOUT{RESET}",
        0x0091 : f"{RED}{header}Failed to send message due to HAL_ERROR{RESET}",
        0x0092 : f"{RED}{header}Failed to send message due to HAL_BUSY{RESET}",
        0x0093 : f"{RED}{header}Failed to send message due to HAL_TIMEOUT{RESET}",
        0x1000 : f"{RED}{header}Invalid arguments are passed to proxy SDK.{RESET}",
        0x1001 : f"{RED}{header}Failed to establish communication with device{RESET}",
        0x1002 : f"{RED}{header}Failed to receive message from device{RESET}",
        0x1003 : f"{RED}{header}Failed to receive message from device in timely manner{RESET}",
        0x1004 : f"{RED}{header}Failed to send message to device{RESET}",
        0x1005 : f"{RED}{header}Failed to send message to device in timely manner{RESET}",
        0x1006 : f"{RED}{header}Invalid message received from the device{RESET}",
        0x1007 : f"{RED}{header}Provisioning server failed to process the request{RESET}",
        0xEEEE : f"{RED}{header}Can't execute Commscope provisionning{RESET}"
    }

    # Get the full path to the DLL file
    script_dir = os.path.dirname(os.path.abspath(__file__))
    dll_path = os.path.join(script_dir, 'proxy_sdk_V5_3\\x64\\dll\\pkiw_proxy_sdk_demo.dll')

    # Wait for board to boot
    time.sleep(1)

    # Load the DLL
    try:
        my_dll = ctypes.WinDLL(dll_path)
    except OSError as e:
        common.thread_safe_print(f"{RED}{header}Failed to load DLL: {e}{RESET}")
        return("Can't execute Commscope provisionning", common.RET_ERROR)

    # Define the function prototype
    pkiw_provision_dac = my_dll.pkiw_provision_dac
    
    # Commscope 2.5.2
    # __declspec(dllexport) int pkiw_provision_dac(const char* com_port,
    #                                              uint32_t pki_type_id,
    #                                              const uint8_t* pki_type_key,
    #                                              size_t pki_type_key_len,
    #                                              const char* pkiw_fqdn,
    #                                              uint8_t provision_mode);

    # Define the argument types
    pkiw_provision_dac.argtypes = [
        ctypes.c_char_p,                 # const char* com_port
        ctypes.c_uint32,                 # uint32_t pki_type_id
        ctypes.POINTER(ctypes.c_uint8),  # const uint8_t* pki_type_key
        ctypes.c_size_t,                 # size_t pki_type_key_len
        ctypes.c_char_p,                 # const char* pkiw_fqdn
        ctypes.c_uint8                   # uint8_t provision_mode
    ]

    pkiw_provision_dac.restype = ctypes.c_int  # It returns an integer
    
    # Values for the arguments
    com_port = port.encode('utf-8')  # Convert string to bytes
    
    # Open pki type ID from text file
    pki_type_id = common.readIntegerFromFile(header, 'PKIWorks_SDK/pkitype.txt')
    if pki_type_id is None:
        return("Can't execute Commscope provisionning", common.RET_ERROR)

    # Open pki type key from binary file
    pki_type_key = common.readBinaryFileToByteList(header, 'PKIWorks_SDK/ats.bin')
    if pki_type_key is None:
        return("Can't execute Commscope provisionning", common.RET_ERROR)

    pki_type_key_len = len(pki_type_key)
    pkiw_fqdn = b'opus-integ.pki-center.com' # Staging Server : opus-integ.pki-center.com
                                             # Production Server : opus.pki-center.com

    # Convert the bytes key to a ctypes array of unsigned bytes
    pki_type_key_array = (ctypes.c_ubyte * len(pki_type_key))(*pki_type_key)
    
    try:
        result = pkiw_provision_dac(
            com_port,
            pki_type_id,
            pki_type_key_array,
            pki_type_key_len,
            pkiw_fqdn,
            provision_mode,
        )
    except Exception as e:
        # print(f"An error occurred while calling the DLL function: {e}")
        return(f"An error occurred while calling the DLL function: {e}", common.RET_ERROR)
    
    if result in ReturnedValues:
        text = ReturnedValues[result]
    else:
        text = f"{RED}{header}Unknown error ({result}){RESET}"
    if result == 0X0000:
        return(text, common.RET_OK)
    else:
        return(text, common.RET_ERROR)
    
