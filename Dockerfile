# Use a base image with Ubuntu as the OS
FROM debian:bookworm

RUN apt-get update

RUN apt-get install \
    git wget cmake  stlink-tools \
    # build tools for openocd
    libhidapi-hidraw0 \
    libusb-0.1-4 \
    libusb-1.0-0 \
    libhidapi-dev \
    libusb-1.0-0-dev \
    libusb-dev \
    libtool \ 
    make \
    automake \
    pkg-config \
    tclsh \
    telnet \
    openocd \
    libncurses5 \
    python3 \
    bzip2 \
    -y

# Install arm-none-eabi compiler
RUN wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2
RUN tar xf gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2
RUN cp -rf gcc-arm-none-eabi-10.3-2021.10/* /usr/local/
RUN rm -rf gcc-arm-none-eabi-10.3-2021.10

CMD bin/bash