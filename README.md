# stm32f1
Docker container for stm32 development..

**This Project is a template which can be copied and modified for complex projects**

## Setup FAQs
1. In the Dockerfile ensure that xpack-dev-tools/arm-none-eabi-gcc is to a latest version, otherwise clashes with openocd
- Current GCC-ARM Version: **10.3.2021.10**

## Windows Setup (Currently Work in Progress)
Windows doesnot allow Docker to access the USB Devices, thus ST-Link becomes unavailable for our Docker Container, a workaround can be to forward the usb to IP which can be accessed by the Docker

1. For setup of usbip on windows follow this tutorial - [https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/using-docker-container.md]
2. Ensure that wsl is updated - otherwise update using this tutorial - [https://superuser.com/questions/1709437/how-can-i-update-the-kernel-in-wsl2-kernel-to-latest-release]

## Linux Setup

1. Ensure that docker is installed


## Building the Project:
1. Press Ctrl+Shift+P, search Task Run
2. Select the option build-debug
3. The Project will build and output files can be then seen in build folder

## Flashing the Project
1. Connect the ST-Link to the PC, with appropriate Connection made with the Target Board. 
2. If using any of the STM32 Boards with Boot Pins Settings, check the Settings
    - STM32F1 Blue pill board - [https://www.electronicshub.org/getting-started-with-stm32f103c8t6-blue-pill/]
3. Press Ctrl+Shift+P, Search Task Run
4. Select the Option flash
5. The executable will be flashed to the Board

## Debugging the Project
1. In the Debug Options, select appropriate Debug Configuration based on the STM Board
2. Debug the Project - Here note that position of Boot Pins (If there), becomes necessary to debug the project. If not appropriate then undefined behaviour can be seen.
