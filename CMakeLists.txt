cmake_minimum_required(VERSION 3.16)

# Setup toolchian
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/build-tool/cmake/stm32_gcc.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

#set Driver Path
set(DRIVERS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/BSP/Drivers/STM32F1xx_HAL_Driver/Src)
set(DRIVERS_INC ${CMAKE_CURRENT_SOURCE_DIR}/BSP/Drivers/STM32F1xx_HAL_Driver/Inc)

file(GLOB SRC_FILES 
        "${DRIVERS_PATH}/stm32f1xx_hal_uart.c"
        "${DRIVERS_PATH}/stm32f1xx_hal_rcc.c"
        "${DRIVERS_PATH}/stm32f1xx_hal_dma.c"
        "${DRIVERS_PATH}/stm32f1xx_hal_cortex.c"
        
        
)

#mcuboot
# Set MCUBoot Path
set(MCUBOOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/mcuboot/boot/bootutil)
set(MCUBOOT_SRC_DIR ${MCUBOOT_PATH}/src)
set(MCUBOOT_INC_DIR ${MCUBOOT_PATH}/include)
set(TINYCRYPT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/mcuboot/ext/tinycrypt/lib)
set(TINYCRYPT_SRC_DIR ${TINYCRYPT_DIR}/source)
set(TINYCRYPT_INC_DIR ${TINYCRYPT_DIR}/include)


set(MCUBOOT_SRC_FILES
${MCUBOOT_SRC_DIR}/boot_record.c 
${MCUBOOT_SRC_DIR}/bootutil_misc.c 
${MCUBOOT_SRC_DIR}/caps.c 
${MCUBOOT_SRC_DIR}/encrypted.c 
${MCUBOOT_SRC_DIR}/fault_injection_hardening.c 
${MCUBOOT_SRC_DIR}/fault_injection_hardening_delay_rng_mbedtls.c 
${MCUBOOT_SRC_DIR}/image_ecdsa.c 
#${MCUBOOT_SRC_DIR}/image_ec256.c 
${MCUBOOT_SRC_DIR}/image_ed25519.c 
${MCUBOOT_SRC_DIR}/image_rsa.c 
${MCUBOOT_SRC_DIR}/image_validate.c 
${MCUBOOT_SRC_DIR}/loader.c 
${MCUBOOT_SRC_DIR}/swap_misc.c 
${MCUBOOT_SRC_DIR}/swap_move.c 
${MCUBOOT_SRC_DIR}/swap_scratch.c 
${MCUBOOT_SRC_DIR}/tlv.c
src/mcuboot_port.c
)

set(TINYCRYPT_SRC_FILES
  ${TINYCRYPT_SRC_DIR}/aes_decrypt.c 
  ${TINYCRYPT_SRC_DIR}/aes_encrypt.c 
  ${TINYCRYPT_SRC_DIR}/cbc_mode.c 
  ${TINYCRYPT_SRC_DIR}/ccm_mode.c 
  ${TINYCRYPT_SRC_DIR}/cmac_mode.c 
  ${TINYCRYPT_SRC_DIR}/ctr_mode.c 
  ${TINYCRYPT_SRC_DIR}/ctr_prng.c 
  ${TINYCRYPT_SRC_DIR}/hmac.c 
  ${TINYCRYPT_SRC_DIR}/hmac_prng.c 
  ${TINYCRYPT_SRC_DIR}/sha256.c 
  ${TINYCRYPT_SRC_DIR}/utils.c
  )

# set project
project(stm32f1 C ASM)

# Set build options
set(USE_HAL 1)

# Setup cubemx directory
set(STM32_CUBE_F1_PATH ${CMAKE_CURRENT_SOURCE_DIR}/BSP)

# Get CMSIS package needed for compilation
find_package(CMSIS COMPONENTS STM32F10X REQUIRED)

# mcboot
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/mcuboot/boot/bootutil)

# Set project sources
set(PROJECT_SOURCES
    src/main.c
    src/uart.c
    src/stm32f1xx_it.c
    src/gpio.c
    ${SRC_FILES}
    ${MCUBOOT_SRC_FILES}
    ${TINYCRYPT_SRC_FILES}
)

# Set project includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${DRIVERS_INC} ${MCUBOOT_INC_DIR} ${TINYCRYPT_INC_DIR})

# Include HAL if required else only use CMSIS
if (${USE_HAL})
    message("Building with HAL")
    add_definitions(-DUSE_HAL)
    find_package(HAL COMPONENTS STM32F10X REQUIRED)
    set(LIBRARIES CMSIS::STM32::F103C8 HAL::STM32::F1::GPIO)
else()
    message("Building without HAL")
    set(LIBRARIES CMSIS::STM32::F103C8)
endif()

# Set the project executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Link libraries to executable based on HAL or CMSIS
target_link_libraries(${PROJECT_NAME}
 ${LIBRARIES}
 STM32::NoSys
)

# Generated wanted files and printout debug information
stm32_print_size_of_target(${PROJECT_NAME})
stm32_generate_binary_file(${PROJECT_NAME})
stm32_generate_hex_file(${PROJECT_NAME})