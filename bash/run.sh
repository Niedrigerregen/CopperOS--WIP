cd CopperOS
qemu-system-x86_64 \
  -kernel iso/boot/bzImage \
  -initrd iso/boot/rootfs.cpio \
  -append "console=ttyS0" \
  -nographic