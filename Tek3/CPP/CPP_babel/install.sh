#!/bin/bash

export ALSA_CONFIG_DIR=/usr/share/alsa
rm -fr ~/.conan/data/libalsa/1.1.9/_/_/package/$(ls ~/.conan/data/libalsa/1.1.9/_/_/package)/lib/alsa-lib
rm -fr ~/.conan/data/libalsa/1.1.9/_/_/package/$(ls ~/.conan/data/libalsa/1.1.9/_/_/package)/lib/pkgconfig

ln -s /usr/lib64/alsa-lib/ ~/.conan/data/libalsa/1.1.9/_/_/package/$(ls ~/.conan/data/libalsa/1.1.9/_/_/package)/lib/
ln -s /usr/lib64/pkgconfig/ ~/.conan/data/libalsa/1.1.9/_/_/package/$(ls ~/.conan/data/libalsa/1.1.9/_/_/package)/lib/

# export ALSA_CONFIG_DIR=/usr/share/alsa for config dir
# ln -s /usr/lib64/alsa-lib/ ~/.conan/data/libalsa/<VERSION>/_/_/package/<HASH>/lib/ for plugin dir
# ln -s /usr/lib64/pkgconfig/ ~/.conan/data/libalsa/<VERSION>/_/_/package/<HASH>/lib/ for pkg dir
# $(ls ~/.conan/data/libalsa/1.1.9/_/_/package)