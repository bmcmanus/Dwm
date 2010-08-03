# $Id: PKGBUILD,v 1.24 2009/07/15 13:36:12 spupykin Exp $
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Dag Odenhall <dag.odenhall@gmail.com>
# Contributor: Grigorios Bouzakis <grbzks@gmail.com>

pkgname=dwm
pkgver=5.8.2
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
license=('MIT')
options=(zipman)
depends=('libx11')
install=dwm.install
source=(dwm-$pkgver.tar.gz \
	dwm-$pkgver-bstack.diff \
	dwm-$pkgver-statuscolors.diff \
	dwm-$pkgver-pango.diff \
	dwm-$pkgver-uselessgap.diff)
. md5sums
build() {
  cd $srcdir/$pkgname-$pkgver
  cp ../../config.def.h config.h
  patch -p1 < ../dwm-$pkgver-pango.diff
  patch -p1 < ../dwm-$pkgver-statuscolors.diff
  patch -p1 < ../dwm-$pkgver-bstack.diff
  patch -p1 < ../dwm-$pkgver-uselessgap.diff
  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11 || return 1
  make PREFIX=/usr DESTDIR=$pkgdir install || return 1

  install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE && \
  install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
}
