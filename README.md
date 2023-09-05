# stm32f1
Docker container for stm32 development..

## Setup FAQs
1. In the Dockerfile ensure that xpack-dev-tools/arm-none-eabi-gcc is to a latest version, otherwise clashes with openocd
2. For setup of usbip on windows follow this tutorial - [https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/using-docker-container.md]
3. Ensure that wsl is updated - otherwise update using this tutorial - [https://superuser.com/questions/1709437/how-can-i-update-the-kernel-in-wsl2-kernel-to-latest-release]
