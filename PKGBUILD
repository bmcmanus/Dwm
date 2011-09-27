# $Id: PKGBUILD 54496 2011-08-19 09:22:43Z spupykin $
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Dag Odenhall <dag.odenhall@gmail.com>
# Contributor: Grigorios Bouzakis <grbzks@gmail.com>

pkgname=dwm-scotty
pkgver=5.9
pkgrel=2
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
license=('MIT')
options=(zipman)
provides=('dwm')
conflicts=('dwm')
depends=('libx11' 'libxinerama' 'pango')
install=dwm.install
source=(dwm-$pkgver.tar.gz \
	dwm-$pkgver-bstack.diff \
	dwm-$pkgver-statuscolors.diff \
	dwm-$pkgver-pango.diff \
	dwm-$pkgver-uselessgap.diff \
	dwm.desktop)
. md5sums
build() {
  cd $srcdir/dwm-$pkgver
  cp ../../config.def.h config.h
  sed -i 's/CPPFLAGS =/CPPFLAGS +=/g' config.mk
  sed -i 's/^CFLAGS = -g/#CFLAGS += -g/g' config.mk
  sed -i 's/^#CFLAGS = -std/CFLAGS += -std/g' config.mk
  sed -i 's/^LDFLAGS = -g/#LDFLAGS += -g/g' config.mk
  sed -i 's/^#LDFLAGS = -s/LDFLAGS += -s/g' config.mk
  patch -p1 < ../dwm-$pkgver-pango.diff
  patch -p1 < ../dwm-$pkgver-statuscolors.diff
  patch -p1 < ../dwm-$pkgver-bstack.diff
  patch -p1 < ../dwm-$pkgver-uselessgap.diff
  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11

}
package() {
  cd $srcdir/dwm-$pkgver
  make PREFIX=/usr DESTDIR=$pkgdir install
  install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE
  install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
  install -m644 -D $srcdir/dwm.desktop $pkgdir/usr/share/xsessions/dwm.desktop
}
