//shutdown command. pretty self-explanatory right?

#include <sys/reboot.h>

void shutdown_system() {
    printf("please don't let me die, i'm a live OS! Nooooo *vanishes into the void*\n");
    reboot(RB_POWER_OFF);
}