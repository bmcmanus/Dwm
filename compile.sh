#!/bin/sh
diff -urpN *source *patched > dwm-5.6.1.diff
makepkg -g > md5sums
makepkg -fi
