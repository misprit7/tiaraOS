#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/tiaraos.kernel isodir/boot/tiaraos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "tiaraos" {
	multiboot /boot/tiaraos.kernel
}
EOF
grub-mkrescue -o tiaraos.iso isodir
