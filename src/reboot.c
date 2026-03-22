//reboot command reboots the system

#include <sys/reboot.h>

void reboot_system() {
    printf("Rebooting CopperOS. See you in a bit!\n");
    reboot(RB_AUTOBOOT);
}