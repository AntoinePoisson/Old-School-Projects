FROM epitechcontent/epitest-docker

COPY . /

RUN sudo dnf update -y
RUN sudo dnf install -y libfontenc-devel libXrandr-devel libXv-devel libXcursor-devel libXinerama-devel libXdmcp-devel libXtst-devel libXtst-devel xorg-x11-xkb-utils-devel xorg-x11-xkb-utils-devel libXres-devel libXScrnSaver-devel libXvMC-devel xorg-x11-xtrans-devel xkeyboard-config-devel libXcomposite-devel libXaw-devel libfontenc-devel libXcomposite-devel xcb-util-wm-devel xcb-util-keysyms-devel xcb-util-renderutil-devel libXdamage-devel
RUN sudo python3 -m pip install --upgrade pip
RUN sudo pip3 install configparser
RUN sudo pip3 install backports.lzma
RUN sudo pip3 install conan

RUN conan remote add bincraft https://api.bintray.com/conan/bincrafters/public-conan
RUN conan remote add epitech_remote https://api.bintray.com/conan/epitech/public-conan
RUN conan remote add conancenter https://api.bintray.com/conan/conan/conan-center
RUN conan profile new default --detect
RUN conan profile update settings.compiler.libcxx=libstdc++11 default

RUN chmod +x *.sh
RUN rm -frv ./build/
RUN rm -frv ./CMakeFiles/
RUN rm -frv ./CMakeCache.txt
RUN rm -frv ./cmake_install.cmake
RUN rm -frv ./fclean
RUN rm -frv ./r-type_server
RUN rm -frv ./r-type_client
RUN rm -frv ./vgcore.*
RUN mkdir build
RUN cd build
RUN conan install .. --build=missing
RUN cmake .. -G "Unix Makefiles"
RUN cmake -build .
RUN make -j 4

