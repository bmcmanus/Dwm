#!/bin/sh
#diff -urpN *source *patched > dwm-5.8.2.diff
rm -rf src/
makepkg -g > md5sums
makepkg -fi
