//reboot command reboots the system

#include <stdio.h>
#include <sys/reboot.h>
#include <unistd.h>

int main() {
    printf("Rebooting CopperOS. See you in a bit!\n");
    sync();
    reboot(RB_AUTOBOOT);
    return 0;
}