#!/bin/sh
diff -urpN *source *patched > dwm-5.7.2.diff
makepkg -g > md5sums
makepkg -fi
