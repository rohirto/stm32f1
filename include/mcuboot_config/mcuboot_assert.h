/**
 * @file mcuboot_assert.h
 * @author rohirto
 * @brief mcuboot_assert implementation
 * @version 0.1
 * @date 2024-04-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef _MCUBOOT_ASSERT_H
#define _MCUBOOT_ASSERT_H

#pragma once

#include "stm32f1xx_hal_conf.h"

extern void assert_failed(const char* file, uint32_t line);

#define assert(exp) \
  do {                                                  \
    if (!(exp)) {                                       \
      assert_failed(__FILE__, __LINE__);       \
    }                                                   \
  } while (0)

#endif