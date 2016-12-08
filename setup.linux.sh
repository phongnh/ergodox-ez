#!/usr/bin/env bash
sudo apt-get update
sudo apt-get install gcc-avr avr-libc dfu-programmer

mkdir -p ~/src
cd ~/src
if [ -d qmk_firmware ]; then
    cd qmk_firmware ; git fetch -p ; git reset --hard HEAD
else
    git clone https://github.com/jackhumbert/qmk_firmware
fi

MY_KEYMAP="$HOME/src/qmk_firmware/keyboards/ergodox/keymaps/$(whoami)"
if [ -d "$MY_KEYMAP" ]; then
    cd "$MY_KEYMAP" ; git fetch -p ; git reset --hard origin/HEAD
else
    git clone https://github.com/phongnh/ergodox-ez "$MY_KEYMAP"
fi

cd ~/src/qmk_firmware/keyboards/ergodox
make ez-`whoami`-clean
