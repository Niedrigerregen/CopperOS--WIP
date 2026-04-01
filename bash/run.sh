cd CopperOS
qemu-system-x86_64 \
  -kernel path/to/bzImage \
  -initrd path/to/rootfs.cpio \
  -m 1024 \ 
  -smp 2 \ # sorry to the single-core dudes out there - get a better Computer. Wait, i just realized this DOS-like OS can't run on old MS-DOS Computers
  -nographic \
  -append "console=ttyS0 root=/dev/ram rdinit=/init"