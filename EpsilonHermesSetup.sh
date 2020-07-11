#!/usr/bin/env bash
echo 'deb http://www.rabbitmq.com/debian/ testing main' | sudo tee /etc/apt/sources.list.d/rabbitmq.list
sudo apt-get install -y cmake \
        openssl \
        libssl-dev \
        libblkid-dev \
        e2fslibs-dev \
        libaudit-dev \
        software-properties-common \
        build-essential \
        mesa-common-dev \
        libgl1-mesa-dev \
        python3-pip \
        rabbitmq-server \
        python3-setuptools

pip3 install --user conan
echo 'export PATH=$PATH:~/.local/bin/' >> ~/.profile
source ~/.profile
conan remote add conan-dbely https://api.bintray.com/conan/dbely/conan 
