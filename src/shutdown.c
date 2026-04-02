//shutdown command. pretty self-explanatory right?

#include <sys/reboot.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    printf("please don't let me die, i live in an emulator! Nooooo *vanishes into the void*\n");
    sync();
    reboot(RB_POWER_OFF);
    return(0);
}