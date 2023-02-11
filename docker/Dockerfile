# Docker name 
# charlesdias/stm32f4_build
#
# docker build
# docker build -t charlesdias/stm32f4_build:<version> -t charlesdias/stm32f4_build:latest .
#
# docker push
# docker push charlesdias/stm32f4_build --all-tags

FROM ubuntu:22.04

LABEL maintainer="Charles Dias <charlesdias@tecnofuturo.com.br>"

ENV TZ=America/Fortaleza
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Download Linux support tools
RUN apt-get update && apt-get clean && apt-get install -y \
      build-essential git wget python3 doxygen graphviz gcovr lcov \
      python3-pip flawfinder \
      && apt-get clean && rm -rf /var/lib/apt/lists/*

# Install Lizard
RUN pip3 install lizard

# Get and install the CMake
RUN wget https://github.com/Kitware/CMake/releases/download/v3.25.2/cmake-3.25.2-linux-x86_64.sh \
      -q -O /tmp/cmake-install.sh \
      && chmod u+x /tmp/cmake-install.sh \
      && mkdir /usr/bin/cmake \
      && /tmp/cmake-install.sh --skip-license --prefix=/usr/bin/cmake \
      && rm /tmp/cmake-install.sh

# Set up the CMake path
ENV PATH="/usr/bin/cmake/bin:${PATH}"

# Copy the GNU tools for STM32
RUN mkdir -p /opt/gnu-tools-for-stm32
COPY tools /opt/gnu-tools-for-stm32
# Set up the GNU compiler path
ENV PATH="/opt/gnu-tools-for-stm32/bin:${PATH}"

# # Clone and install Google Test framework. Install in /usr/local/ by default
# RUN git clone -b v1.12.1 https://github.com/google/googletest.git /googletest \
#     && cd /googletest \
#     && mkdir -p build && cd build \
#     && cmake .. && make && make install \
#     && cd / && rm -rf /googletest

# Set up the working directory
WORKDIR /home/project