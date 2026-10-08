/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include "app_config.h"

#if (OTA_SUPPORT == 1)
/* Matter cluster */
#include <app/clusters/ota-requestor/OTADownloader.h>
#include <app/clusters/ota-requestor/OTARequestorInterface.h>
/* ST OTA implementation */
#include "OTAImageProcessorImpl.h"
#include "ota.h"
#include "stm32_int_flash.h"
#include "stm32_ota_flash.h"
#include "w6x_api.h"
#include "w6x_types.h"
#include "app_entry.h"

#define ST67_OTA_HEADER_SIZE 512
#define STM_HEADER_SIZE 8


static uint32_t mCPU1Size;
static uint32_t mCPU2Size;
static bool stm_header_decoded;
static uint32_t mDownloadedBytesCPU2;
static uint16_t mSTHeaderBuffLastBytes;
static uint8_t mST67HeaderBuff[ST67_OTA_HEADER_SIZE];
static uint8_t mWriteST67Header;
static uint8_t mSwitchDwlSlot;

namespace chip {

bool OTAImageProcessorImpl::DeleteImages(
		OTAImageProcessorImpl *imageProcessor) {
	ChipLogProgress(DeviceLayer, "DeleteImages");
	HAL_StatusTypeDef status;

	// SLOT A
	status = FLASH_Erase(SLOT_DWL_A_START_PTR, SLOT_DWL_A_SIZE);
	if (status != HAL_OK) {
		ChipLogError(SoftwareUpdate, "Delete image Slot A failed");
		imageProcessor->mDownloader->EndDownload(CHIP_ERROR_WRITE_FAILED);
		return false;
	}

	return true;
}

bool OTAImageProcessorImpl::IsFirstImageRun() {
	OTARequestorInterface *requestor = chip::GetRequestorInstance();

	/* check pointers */
	if (requestor == nullptr) {
		return false;
	}

	return (requestor->GetCurrentUpdateState()
			== OTARequestorInterface::OTAUpdateStateEnum::kApplying);
}

CHIP_ERROR OTAImageProcessorImpl::ConfirmCurrentImage() {
	ChipLogProgress(DeviceLayer, "OTA Confirm current image");
	OTARequestorInterface *requestor = chip::GetRequestorInstance();

	if (requestor == nullptr) {
		return CHIP_ERROR_INTERNAL;
	}

	uint32_t currentVersion;
	uint32_t targetVersion = requestor->GetTargetVersion();
	ReturnErrorOnFailure(
			DeviceLayer::ConfigurationMgr().GetSoftwareVersion(currentVersion));

	if (currentVersion != targetVersion) {
		ChipLogError(SoftwareUpdate,
				"Current software version = %" PRIu32 ", expected software version = %" PRIu32,
				currentVersion, targetVersion);
		return CHIP_ERROR_INCORRECT_STATE;
	}

	return CHIP_NO_ERROR;
}

CHIP_ERROR OTAImageProcessorImpl::PrepareDownload() {

	// Get OTA status - under what circumstances does prepared break?
	// what happens if a prepare is pending and another one is invoked
	// Should we store the state here and wait until we receive notification

	mHeaderParser.Init();

	DeviceLayer::PlatformMgr().ScheduleWork(HandlePrepareDownload,
			reinterpret_cast<intptr_t>(this));
	return CHIP_NO_ERROR;
}

CHIP_ERROR OTAImageProcessorImpl::ProcessHeader(ByteSpan &block) {
	ChipLogProgress(DeviceLayer, "OTA Process Header");
	if (mHeaderParser.IsInitialized()) {
		OTAImageHeader header;
		CHIP_ERROR error = mHeaderParser.AccumulateAndDecode(block, header);

		// Needs more data to decode the header
		VerifyOrReturnError(error != CHIP_ERROR_BUFFER_TOO_SMALL,
				CHIP_NO_ERROR);
		ReturnErrorOnFailure(error);

		mParams.totalFileBytes = header.mPayloadSize;
		mHeaderParser.Clear();

		// Load Ota_ImageHeader_t header structure and call application callback to validate image header
		Ota_ImageHeader_t OtaImgHeader;
		this->mSwVer = header.mSoftwareVersion; // Store software version in imageProcessor as well
		OtaImgHeader.vendorId = header.mVendorId;
		OtaImgHeader.productId = header.mProductId;
		OtaImgHeader.softwareVersion = header.mSoftwareVersion;
		OtaImgHeader.minApplicableVersion =
				header.mMinApplicableVersion.ValueOr(0);
		OtaImgHeader.maxApplicableVersion =
				header.mMaxApplicableVersion.ValueOr(0);

		if (true != OtaHeaderValidation(OtaImgHeader)) {
			ChipLogProgress(DeviceLayer, "OtaHeaderValidation error");
			return CHIP_ERROR_INCORRECT_STATE;
		}
	}

	return CHIP_NO_ERROR;
}

CHIP_ERROR OTAImageProcessorImpl::Finalize() {
	ChipLogProgress(DeviceLayer, "OTA Finalize");
	DeviceLayer::PlatformMgr().ScheduleWork(HandleFinalize,
			reinterpret_cast<intptr_t>(this));
	return CHIP_NO_ERROR;
}

CHIP_ERROR OTAImageProcessorImpl::Apply() {
	uint8_t ret_w6x = 0;
	uint8_t error = 0;

	 ChipLogProgress(SoftwareUpdate, "Applying - resetting device");
	// update st67
	ret_w6x = W6X_OTA_Finish();
	if (ret_w6x != 0) {
		ChipLogError(SoftwareUpdate, "Cannot finish ota from st67 side");
		ChipLogProgress(SoftwareUpdate, "Download failed st67 error");
		GetRequestorInstance()->CancelImageUpdate();
		return CHIP_ERROR_INTERNAL;
	}

	// update host: NonSecure App and secure App
	if ((mCPU1Size <= SLOT_DWL_A_SIZE)) {

		ChipLogProgress(DeviceLayer, "OTA Write Magic Trailer");
		if (STM_OTA_FLASH_WriteMagicTrailer() != 0) {
			ChipLogError(SoftwareUpdate, "Flash write failed (Magic value)");
			GetRequestorInstance()->CancelImageUpdate();
			return CHIP_ERROR_INTERNAL;
		}
	} else {
		ChipLogError(SoftwareUpdate, "Not enough space to write Magic value");
		GetRequestorInstance()->CancelImageUpdate();
		return CHIP_ERROR_INTERNAL;
	}

	//write  software version in nvm for validation for next reboot
	error = NVM_SetKeyValue((char*) X_CUBE_MATTER_VERSION, SOFTWARE_VERSION_KEY,
			sizeof(X_CUBE_MATTER_VERSION), SECTOR_MATTER);
	if (error != 0) {
		return CHIP_ERROR_INTERNAL;
	}
	NVM_Dump();

	/* Trigger system reset */
	NVIC_SystemReset();

	return CHIP_NO_ERROR;
}

CHIP_ERROR OTAImageProcessorImpl::Abort() {
	DeviceLayer::PlatformMgr().ScheduleWork(HandleAbort,
			reinterpret_cast<intptr_t>(this));
	return CHIP_NO_ERROR;
}

CHIP_ERROR OTAImageProcessorImpl::ProcessBlock(ByteSpan &block) {
	/* check pointers */
	if ((block.data() == nullptr) || block.empty()) {
		return CHIP_ERROR_INVALID_ARGUMENT;
	}

	CHIP_ERROR err = ProcessHeader(block);
	if (err != CHIP_NO_ERROR) {
		ChipLogError(SoftwareUpdate, "Matter image header parser error %s",
				chip::ErrorStr(err));
		this->mDownloader->EndDownload(CHIP_ERROR_INVALID_FILE_IDENTIFIER);
		return err;
	}

	// Store block data for HandleProcessBlock to access
	err = SetBlock(block);
	if (err != CHIP_NO_ERROR) {
		ChipLogError(SoftwareUpdate,
				"Cannot set block data: %" CHIP_ERROR_FORMAT, err.Format());
		return err;
	}

	DeviceLayer::PlatformMgr().ScheduleWork(HandleProcessBlock,
			reinterpret_cast<intptr_t>(this));
	return CHIP_NO_ERROR;
}

void OTAImageProcessorImpl::HandlePrepareDownload(intptr_t context) {
	auto *imageProcessor = reinterpret_cast<OTAImageProcessorImpl*>(context);
	uint8_t ret_w6x = 0;
	ChipLogProgress(DeviceLayer, "OTA Prepare DL");

	/* check pointers */
	if (imageProcessor == nullptr) {
		ChipLogError(SoftwareUpdate, "ImageProcessor context is null");
		return;
	} else if (imageProcessor->mDownloader == nullptr) {
		ChipLogError(SoftwareUpdate, "mDownloader is null");
		return;
	}

	// running this in a thread so won't block main event loop
	ChipLogProgress(SoftwareUpdate, "HandlePrepareDownload");

	/* Delete image slots */
	if (!DeleteImages(imageProcessor)) {
		return;
	}

	//trigger ota on st67 side
	/* Terminate OTA transmission on ST67 side to ensure clear state */
	ret_w6x = W6X_OTA_Starts(0);
	if (ret_w6x != 0) {
		ChipLogError(SoftwareUpdate, "Cannot start ota from st67 side");
		return;
	}

	/* Starts OTA on ST67 side */
	ret_w6x = W6X_OTA_Starts(1);
	if (ret_w6x != 0) {
		ChipLogError(SoftwareUpdate, "Cannot start ota from st67 side");
		return;
	}

	// Initialize tracking variables
	imageProcessor->mParams.downloadedBytes = 0;
	stm_header_decoded = false;
	mDownloadedBytesCPU2 = 0;
	mSTHeaderBuffLastBytes = 0;
	mSwitchDwlSlot = false; // start with dwl_slot1 for CPU1
	mWriteST67Header = true; // need to write st67 header
	imageProcessor->mDownloader->OnPreparedForDownload(CHIP_NO_ERROR);
}

void OTAImageProcessorImpl::HandleFinalize(intptr_t context) {
	ChipLogProgress(SoftwareUpdate, "HandleFinalize");

	auto *imageProcessor = reinterpret_cast<OTAImageProcessorImpl*>(context);
	/* check pointers */
	if (imageProcessor == nullptr) {
		return;
	}

	if (imageProcessor->mParams.downloadedBytes
			!= (STM_OTA_FLASH_GetWritedBlock() + mDownloadedBytesCPU2
					+ STM_HEADER_SIZE)) {
		ChipLogProgress(SoftwareUpdate,
				"Download failed not align with total bytes write in flash and st67");
		imageProcessor->mDownloader->EndDownload(
		CHIP_ERROR_WRITE_FAILED);
		// Start from scratch
		imageProcessor->mParams.downloadedBytes = 0;
		stm_header_decoded = false;
		mDownloadedBytesCPU2 = 0;
		mSTHeaderBuffLastBytes = 0;
		mSwitchDwlSlot = false; // start with dwl_slot1 for CPU1
		mWriteST67Header = true; // need to write st67 header
		GetRequestorInstance()->CancelImageUpdate();

	}
	imageProcessor->ReleaseBlock();

	ChipLogProgress(SoftwareUpdate, "HandleFinalize done");
}

void OTAImageProcessorImpl::HandleAbort(intptr_t context) {
	auto *imageProcessor = reinterpret_cast<OTAImageProcessorImpl*>(context);
	/* check pointers */
	if (imageProcessor == nullptr) {
		return;
	}

	ChipLogProgress(SoftwareUpdate, "HandleAbort");

	/* Delete image slots */
	if (!DeleteImages(imageProcessor)) {
		return;
	}

	imageProcessor->ReleaseBlock();

	// Start from scratch
	imageProcessor->mParams.downloadedBytes = 0;
	stm_header_decoded = false;
	mDownloadedBytesCPU2 = 0;
	mSTHeaderBuffLastBytes = 0;
	mSwitchDwlSlot = false; // start with dwl_slot1 for CPU1
	mWriteST67Header = true; // need to write st67 header
}

void OTAImageProcessorImpl::HandleProcessBlock(intptr_t context) {
	auto *imageProcessor = reinterpret_cast<OTAImageProcessorImpl*>(context);

	/* check pointers */
	if (imageProcessor == nullptr) {
		ChipLogError(SoftwareUpdate, "ImageProcessor context is null");
		return;
	}
	if (imageProcessor->mDownloader == nullptr) {
		ChipLogError(SoftwareUpdate, "mDownloader is null");
		return;
	}

	OtaBlockError status = OtaBlockError::None;

	if (mSwitchDwlSlot == false) {
		// CPU1 write in DWL_SLOT 1
		if (!stm_header_decoded) {
			// First block: STM header + first CPU1 data
			status = ProcessCpu1BlockWithStmHeader(imageProcessor);

		} else if ((imageProcessor->mParams.downloadedBytes
				+ static_cast<std::uint32_t>(imageProcessor->mBlock.size()))
				>= (mCPU1Size + STM_HEADER_SIZE)) {
			// Block containing both end of CPU1 and start of CPU2
			status = ProcessCpu1Cpu2BoundaryBlock(imageProcessor);

		} else {
			// Pure CPU1 block
			status = ProcessCpu1DataBlock(imageProcessor);
		}

	} else {
		// CPU2-only data (ST67)
		status = ProcessCpu2DataBlock(imageProcessor);
	}

	if (status == OtaBlockError::None) {
		// Update global downloaded bytes and request next block
		imageProcessor->mParams.downloadedBytes +=
				imageProcessor->mBlock.size();
		imageProcessor->mDownloader->FetchNextData();

	} else {
		if (status == OtaBlockError::Cpu1) {
			ChipLogError(SoftwareUpdate,
					"OTA block processing failed on CPU1 path");
		} else if (status == OtaBlockError::Cpu2) {
			ChipLogError(SoftwareUpdate,
					"OTA block processing failed on CPU2/ST67 path");
		}
	}
}

CHIP_ERROR OTAImageProcessorImpl::SetBlock(ByteSpan &block) {
	if (block.empty()) {
		ReleaseBlock();
		return CHIP_NO_ERROR;
	}

	if (mBlock.size() < block.size()) {
		if (!mBlock.empty()) {
			ReleaseBlock();
		}
		uint8_t *mBlock_ptr = static_cast<uint8_t*>(chip::Platform::MemoryAlloc(
				block.size()));
		if (mBlock_ptr == nullptr) {
			return CHIP_ERROR_NO_MEMORY;
		}
		mBlock = MutableByteSpan(mBlock_ptr, block.size());
	}
	CHIP_ERROR err = CopySpanToMutableSpan(block, mBlock);
	if (err != CHIP_NO_ERROR) {
		ChipLogError(SoftwareUpdate,
				"Cannot copy block data: %" CHIP_ERROR_FORMAT, err.Format());
		return err;
	}

	return CHIP_NO_ERROR;
}

CHIP_ERROR OTAImageProcessorImpl::ReleaseBlock() {
	if (mBlock.data() != nullptr) {
		chip::Platform::MemoryFree(mBlock.data());
	}

	mBlock = MutableByteSpan();
	return CHIP_NO_ERROR;
}

OtaBlockError OTAImageProcessorImpl::ProcessCpu1BlockWithStmHeader(
		OTAImageProcessorImpl *imageProcessor) {
	// First block received, parse STM header and write remaining CPU1 data to DWL_SLOT 1
	uint8_t STMHeader[STM_HEADER_SIZE];

	// Copy STM header from the beginning of the block
	memcpy(STMHeader,
			reinterpret_cast<std::uint8_t*>(imageProcessor->mBlock.data()),
			sizeof(STMHeader));

	// Retrieve CPU1/CPU2 sizes from STM header
	mCPU1Size = STMHeader[0] + (static_cast<uint32_t>(STMHeader[1]) << 8)
			+ (static_cast<uint32_t>(STMHeader[2]) << 16)
			+ (static_cast<uint32_t>(STMHeader[3]) << 24);

	mCPU2Size = STMHeader[4] + (static_cast<uint32_t>(STMHeader[5]) << 8)
			+ (static_cast<uint32_t>(STMHeader[6]) << 16)
			+ (static_cast<uint32_t>(STMHeader[7]) << 24);

	stm_header_decoded = true;

	// Basic header checks (CPU1 size must fit, CPU2 size must be non-zero)
	if ((mCPU1Size > SLOT_DWL_A_SIZE) || (mCPU2Size == 0)) {
		ChipLogError(SoftwareUpdate, "Flash decode failed (invalid STM header)");
		imageProcessor->mDownloader->EndDownload(CHIP_ERROR_DECODE_FAILED);
		return OtaBlockError::Cpu1;
	}

	if (mCPU1Size == 0) {
		// Empty image received for CPU1
		ChipLogError(SoftwareUpdate, "Empty image received for CPU1");
		imageProcessor->mDownloader->EndDownload(CHIP_ERROR_DECODE_FAILED);
		return OtaBlockError::Cpu1;
	}

	// Initialize CPU1 OTA flash
	STM_OTA_FLASH_Init();

	// Write remaining bytes (after STM header) to DWL_SLOT 1
	uint8_t error = STM_OTA_FLASH_WriteChunk(
			reinterpret_cast<std::uint8_t*>(imageProcessor->mBlock.data())
					+ STM_HEADER_SIZE,
			static_cast<std::uint32_t>(imageProcessor->mBlock.size())
					- STM_HEADER_SIZE);

	if (error != 0) {
		ChipLogError(SoftwareUpdate, "Flash write failed for DWL_SLOT 1");
		imageProcessor->mDownloader->EndDownload(CHIP_ERROR_WRITE_FAILED);
		return OtaBlockError::Cpu1;
	}

	ChipLogProgress(DeviceLayer, "OTA Write DATA in slot 1");
	return OtaBlockError::None;
}

OtaBlockError OTAImageProcessorImpl::ProcessCpu1DataBlock(
		OTAImageProcessorImpl *imageProcessor) {
	// Pure CPU1 block: write all data to DWL_SLOT 1
	uint8_t error = STM_OTA_FLASH_WriteChunk(
			reinterpret_cast<std::uint8_t*>(imageProcessor->mBlock.data()),
			static_cast<std::uint32_t>(imageProcessor->mBlock.size()));

	if (error != 0) {
		ChipLogError(SoftwareUpdate, "Flash write failed for DWL_SLOT 1");
		imageProcessor->mDownloader->EndDownload(CHIP_ERROR_WRITE_FAILED);
		return OtaBlockError::Cpu1;
	}

	ChipLogProgress(DeviceLayer, "OTA Write DATA in slot 1");
	return OtaBlockError::None;
}

OtaBlockError OTAImageProcessorImpl::ProcessCpu1Cpu2BoundaryBlock(
		OTAImageProcessorImpl *imageProcessor) {
	uint32_t blockSize = static_cast<uint32_t>(imageProcessor->mBlock.size());

	// Number of CPU1 bytes already received before this block (including STM header)
	uint16_t remainingCPU1 = static_cast<uint16_t>((mCPU1Size + STM_HEADER_SIZE)
			- imageProcessor->mParams.downloadedBytes);

	// Offset in the block where CPU2 (ST67) data begins
	uint16_t cpu2OffsetInBlock = remainingCPU1;

	// Bytes belonging to CPU2 in this block (at the end of the block)
	uint16_t cpu2BytesInBlock = static_cast<uint16_t>(blockSize)
			- remainingCPU1;

	// Reset CPU2 accounting / header fragment state
	mDownloadedBytesCPU2 = 0;
	mSTHeaderBuffLastBytes = 0;

	// Sanity check
	if ((remainingCPU1 > blockSize)
			|| (remainingCPU1 + cpu2BytesInBlock != blockSize)) {
		ChipLogError(SoftwareUpdate, "CPU1/CPU2 split computation error");
		imageProcessor->mDownloader->EndDownload(CHIP_ERROR_WRITE_FAILED);
		return OtaBlockError::Cpu1;
	}

	// CPU1 write in DWL_SLOT 1
	uint8_t error = STM_OTA_FLASH_WriteChunk(
			reinterpret_cast<std::uint8_t*>(imageProcessor->mBlock.data()),
			remainingCPU1);

	if (error != 0) {
		ChipLogError(SoftwareUpdate, "Flash write to DWL_SLOT 1 failed");
		imageProcessor->mDownloader->EndDownload(CHIP_ERROR_WRITE_FAILED);
		return OtaBlockError::Cpu1;
	}
	ChipLogProgress(DeviceLayer, "OTA Write DATA in slot 1");

	// Flush last data to write in DWL_SLOT 1
	error = STM_OTA_FLASH_FlushLastBlock();
	if (error != 0) {
		ChipLogProgress(SoftwareUpdate,
				"Download failed last flush for host failed");
		imageProcessor->mDownloader->EndDownload(CHIP_ERROR_WRITE_FAILED);
		return OtaBlockError::Cpu1;
	}
	ChipLogProgress(DeviceLayer, "OTA Flush last DATA in slot 1");

	// CPU2 part (for ST67) in the same block, if any
	if ((mCPU2Size != 0) && (cpu2BytesInBlock > 0)) {
		if (cpu2BytesInBlock >= ST67_OTA_HEADER_SIZE) {
			// We have the full ST67 header in this block
			error =
					W6X_OTA_Send(
							reinterpret_cast<std::uint8_t*>(imageProcessor->mBlock.data())
									+ cpu2OffsetInBlock,
							ST67_OTA_HEADER_SIZE);
			if (error != 0) {
				ChipLogError(SoftwareUpdate,
						"Flash write to ST67 header failed");
				imageProcessor->mDownloader->EndDownload(
						CHIP_ERROR_WRITE_FAILED);
				return OtaBlockError::Cpu2;
			}
			ChipLogProgress(DeviceLayer, "OTA Write ST67 header");

			uint32_t remainingCpu2Data = static_cast<uint32_t>(cpu2BytesInBlock)
					- ST67_OTA_HEADER_SIZE;

			if (remainingCpu2Data > 0) {
				// Send immediately the CPU2 data after the header (still in this block)
				error =
						W6X_OTA_Send(
								reinterpret_cast<std::uint8_t*>(imageProcessor->mBlock.data())
										+ cpu2OffsetInBlock
										+ ST67_OTA_HEADER_SIZE,
								remainingCpu2Data);
				if (error != 0) {
					ChipLogError(SoftwareUpdate,
							"Flash write to ST67 data failed");
					imageProcessor->mDownloader->EndDownload(
							CHIP_ERROR_WRITE_FAILED);
					return OtaBlockError::Cpu2;
				}
				ChipLogProgress(DeviceLayer, "OTA Write ST67 Data");
			}

			// CPU2 bytes written so far (only this block for now)
			mDownloadedBytesCPU2 = cpu2BytesInBlock;
			// From now on, all following blocks are pure CPU2 data (no header to write again)
			mWriteST67Header = false;
		} else {
			// Not enough bytes in this block to send the entire ST67 header
			// -> store partial header in buffer and defer sending until next block
			memcpy(mST67HeaderBuff,
					reinterpret_cast<std::uint8_t*>(imageProcessor->mBlock.data())
							+ cpu2OffsetInBlock, cpu2BytesInBlock);
			mSTHeaderBuffLastBytes = cpu2BytesInBlock;
			mWriteST67Header = true;
			ChipLogProgress(SoftwareUpdate,
					"Not enough data to write ST67 Header");
		}

		// Switch to ST67 slot for all the next data
		mSwitchDwlSlot = true;
	}

	return OtaBlockError::None;
}

OtaBlockError OTAImageProcessorImpl::ProcessCpu2DataBlock(
		OTAImageProcessorImpl *imageProcessor) {
	uint8_t *blockPtr =
			reinterpret_cast<std::uint8_t*>(imageProcessor->mBlock.data());
	uint32_t blockSize = static_cast<uint32_t>(imageProcessor->mBlock.size());
	uint8_t error = 0;

	// Check if we still need to write the ST67 header
	if (mWriteST67Header == true) {
		if (mSTHeaderBuffLastBytes > 0) {
			// Complete ST67 header using previous fragment + beginning of this block
			memcpy(mST67HeaderBuff + mSTHeaderBuffLastBytes, blockPtr,
			ST67_OTA_HEADER_SIZE - mSTHeaderBuffLastBytes);

			// Send the full ST67 header
			error = W6X_OTA_Send(mST67HeaderBuff, ST67_OTA_HEADER_SIZE);
			if (error != 0) {
				ChipLogError(SoftwareUpdate,
						"Flash write to ST67 header failed");
				imageProcessor->mDownloader->EndDownload(
						CHIP_ERROR_WRITE_FAILED);
				return OtaBlockError::Cpu2;
			}
			mDownloadedBytesCPU2 += mSTHeaderBuffLastBytes;
			ChipLogProgress(DeviceLayer, "OTA Write ST67 header");
		} else {
			// Header fully resides in this block
			error = W6X_OTA_Send(blockPtr, ST67_OTA_HEADER_SIZE);
			if (error != 0) {
				ChipLogError(SoftwareUpdate,
						"Flash write to ST67 header failed");
				imageProcessor->mDownloader->EndDownload(
						CHIP_ERROR_WRITE_FAILED);
				return OtaBlockError::Cpu2;
			}
			ChipLogProgress(DeviceLayer, "OTA Write ST67 header");
		}

		// Send the remaining CPU2 data from this block after the header completion
		uint16_t offset = static_cast<uint16_t>(ST67_OTA_HEADER_SIZE
				- mSTHeaderBuffLastBytes);
		uint16_t dataSize = static_cast<uint16_t>(blockSize) - offset;

		error = W6X_OTA_Send(blockPtr + offset, dataSize);
		if (error != 0) {
			ChipLogError(SoftwareUpdate, "Flash write to ST67 data failed");
			imageProcessor->mDownloader->EndDownload(CHIP_ERROR_WRITE_FAILED);
			return OtaBlockError::Cpu2;
		}
		ChipLogProgress(DeviceLayer, "OTA Write ST67 Data");

		mWriteST67Header = false;
		mDownloadedBytesCPU2 += blockSize;
	} else {
		// All data in this block is pure CPU2 payload
		error = W6X_OTA_Send(blockPtr, blockSize);
		if (error != 0) {
			ChipLogError(SoftwareUpdate, "Flash write to ST67 data failed");
			imageProcessor->mDownloader->EndDownload(CHIP_ERROR_WRITE_FAILED);
			return OtaBlockError::Cpu2;
		}
		ChipLogProgress(DeviceLayer, "OTA Write ST67 Data");
		mDownloadedBytesCPU2 += blockSize;
	}

	return OtaBlockError::None;
}

} // namespace chip

#endif
