/**
 * @file mcuboot_logging.h
 * @author rohirto
 * @brief mcuboot logging.h file
 * @version 0.1
 * @date 2024-04-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _MCUBOOT_LOGGING_H
#define _MCUBOOT_LOGGING_H

#pragma once

#include "uart.h"  //The debug logging function isdefined there

#define MCUBOOT_LOG_MODULE_DECLARE(...)

#define MCUBOOT_LOG_ERR(_fmt, ...) \
  debugLog("[ERR] " _fmt, ##__VA_ARGS__);
#define MCUBOOT_LOG_WRN(_fmt, ...) \
  debugLog("[WRN] " _fmt, ##__VA_ARGS__);
#define MCUBOOT_LOG_INF(_fmt, ...) \
  debugLog("[INF] " _fmt, ##__VA_ARGS__);
#define MCUBOOT_LOG_DBG(_fmt, ...) \
  debugLog("[DBG] " _fmt, ##__VA_ARGS__);

#endif