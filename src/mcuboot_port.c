/**
 * @file mcuboot_port.c
 * @author rohirto
 * @brief mcuboot port functions
 * @version 0.1
 * @date 2024-04-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// mcu_port.c

#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "uart.h"

#include "flash_map_backend/flash_map_backend.h"
//#include "os/os_heap.h"
#include "sysflash/sysflash.h"

//#include "hal/internal_flash.h"

#define BOOTLOADER_START_ADDRESS 0x0
#define BOOTLOADER_SIZE (32 * 1024)
#define APPLICATION_PRIMARY_START_ADDRESS (32 * 1024)
#define APPLICATION_SIZE (40 * 1024)
#define APPLICATION_SECONDARY_START_ADDRESS (APPLICATION_PRIMARY_START_ADDRESS + APPLICATION_SIZE)


static const struct flash_area bootloader = {
  .fa_id = FLASH_AREA_BOOTLOADER,
  .fa_device_id = FLASH_DEVICE_INTERNAL_FLASH,
  .fa_off = BOOTLOADER_START_ADDRESS,
  .fa_size = BOOTLOADER_SIZE,
};

static const struct flash_area primary_img0 = {
  .fa_id = FLASH_AREA_IMAGE_PRIMARY(0),
  .fa_device_id = FLASH_DEVICE_INTERNAL_FLASH,
  .fa_off = APPLICATION_PRIMARY_START_ADDRESS,
  .fa_size = APPLICATION_SIZE,
};

static const struct flash_area secondary_img0 = {
  .fa_id = FLASH_AREA_IMAGE_SECONDARY(0),
  .fa_device_id = FLASH_DEVICE_INTERNAL_FLASH,
  .fa_off = APPLICATION_SECONDARY_START_ADDRESS,
  .fa_size = APPLICATION_SIZE,
};

static const struct flash_area *s_flash_areas[] = {
  &bootloader,
  &primary_img0,
  &secondary_img0,
};

int flash_area_open(uint8_t id, const struct flash_area **area_outp) {
  return -1;
}

void flash_area_close(const struct flash_area *area) {
}

int flash_area_read(const struct flash_area *fa, uint32_t off, void *dst,
                    uint32_t len) {
  return -1;
}

int flash_area_write(const struct flash_area *fa, uint32_t off, const void *src,
                     uint32_t len) {
  return -1;
}

int flash_area_erase(const struct flash_area *fa, uint32_t off, uint32_t len) {
  return -1;
}

size_t flash_area_align(const struct flash_area *area) {
  return 1;
}

uint8_t flash_area_erased_val(const struct flash_area *area) {
  return 0xff;
}

int flash_area_get_sectors(int fa_id, uint32_t *count,
                           struct flash_sector *sectors) {
  return -1;
}

int flash_area_id_from_multi_image_slot(int image_index, int slot) {
  return -1;
}

int flash_area_id_from_image_slot(int slot) {
  return flash_area_id_from_multi_image_slot(0, slot);
}

void assert_failed(const char *file, uint32_t line)
{
   // Print the assertion message with file and line information
    debugLog("Assertion failed: file %s, line %d\r\n", file, line);

    // HAL_Delay(100);  // Add delay if required

    // Halt the program execution or perform any other necessary actions
    // For example, you can reset the microcontroller
    //HAL_NVIC_SystemReset();

    // Alternatively, you can halt the program execution
    // by entering an infinite loop
     while (1) {}
}