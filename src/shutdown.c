//shutdown command. pretty self-explanatory right?

#include <sys/reboot.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    printf("please don't let me die, i'm a live OS! Nooooo *vanishes into the void*\n");
    reboot(RB_POWER_OFF);
    sync();
    return(0);
}