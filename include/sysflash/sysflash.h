/**
 * @file sysflash.h
 * @author rohirto
 * @brief sysflash.h
 * @version 0.1
 * @date 2024-04-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef _SYSFLASH_H
#define _SYSFLASH_H

//! sysflash/sysflash.h

//! A user-defined identifier for different storage mediums
//! (i.e internal flash, external NOR flash, eMMC, etc)
#define FLASH_DEVICE_INTERNAL_FLASH 0   //Using Internal Flash 64kb

//! An arbitrarily high slot ID we will use to indicate that
//! there is not slot
#define FLASH_SLOT_DOES_NOT_EXIST 255

//! NB: MCUboot expects this define to exist but it's only used
//! if MCUBOOT_SWAP_USING_SCRATCH=1 is set
#define FLASH_AREA_IMAGE_SCRATCH FLASH_SLOT_DOES_NOT_EXIST

//! The slot we will use to track the bootloader allocation
#define FLASH_AREA_BOOTLOADER 0

//! A mapping to primary and secondary/upgrade slot
//! given an image_index. We'll plan to use
#define FLASH_AREA_IMAGE_PRIMARY(i) ((i == 0) ? 1 : 255)
#define FLASH_AREA_IMAGE_SECONDARY(i) ((i == 0) ? 2 : 255)

#endif