qemu-system-x86_64 \
  -kernel iso/boot/bzImage \
  -initrd iso/boot/rootfs.cpio \
  -m 1024 \
  -smp 2 \
  -nographic \
  -append "console=ttyS0 root=/dev/ram rdinit=/init"