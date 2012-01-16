#!/bin/sh
rm -rf src/
makepkg -g > md5sums
makepkg -fi
cp dwm*pkg.tar.xz "$HOME/.local/var/local_packages"
