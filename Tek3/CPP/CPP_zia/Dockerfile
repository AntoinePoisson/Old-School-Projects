FROM epitechcontent/epitest-docker

## Update Fedora
# RUN sudo dnf update -y

## Install Mandatory Dependance for Conan
RUN sudo dnf install -y libfontenc-devel      \
        libXrandr-devel                       \
        libXv-devel                           \
        libXcursor-devel                      \
        libXinerama-devel                     \
        libXdmcp-devel                        \
        libXtst-devel                         \
        libXtst-devel                         \
        xorg-x11-xkb-utils-devel              \
        xorg-x11-xkb-utils-devel              \
        libXres-devel                         \
        libXScrnSaver-devel                   \
        libXvMC-devel                         \
        xorg-x11-xtrans-devel                 \
        xkeyboard-config-devel                \
        libXcomposite-devel                   \
        libXaw-devel                          \
        libfontenc-devel                      \
        libXcomposite-devel                   \
        xcb-util-wm-devel                     \
        xcb-util-keysyms-devel                \
        xcb-util-renderutil-devel             \
        libXdamage-devel

## Update Python3
RUN sudo python3 -m pip install --upgrade pip             \
        && pip3 install configparser backports.lzma conan


## Config Conan
RUN conan remote add bincraft https://api.bintray.com/conan/bincrafters/public-conan          \
        && conan remote add epitech_remote https://api.bintray.com/conan/epitech/public-conan \
        && conan remote add conancenter https://api.bintray.com/conan/conan/conan-center      \
        && conan profile new default --detect                                                 \
        && conan profile update settings.compiler.libcxx=libstdc++11 default


## Copy Repo
WORKDIR /app
COPY . /app

## Setup Script
RUN chmod 1777 run.sh  \
    && ./run.sh fclear

## Only Build Project
RUN ./run.sh build

### Running + Build Project
# CMD ["./run.sh"]

