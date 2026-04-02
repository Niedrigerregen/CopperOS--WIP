// Init for CopperOS. Starts basically everything
#include <unistd.h>
#include <sys/mount.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Set PATH so BusyBox applets that are mainly for the internet connection stuff can find the tools
    setenv("PATH", "/bin:/sbin:/usr/bin", 1);

    if (mount("", "/", NULL, MS_REMOUNT, NULL) != 0) { // makes rootfs read-write as per default it's read-only
        perror("remount / rw failed");
    }

    sethostname("copperos", 8);

    system("ip link set lo up");           
    system("ip link set eth0 up 2>/dev/null || ip link set ens3 up 2>/dev/null");
    system("udhcpc -i eth0 -q -n 2>/dev/null || udhcpc -i ens3 -q -n 2>/dev/null || udhcpc -q -n");

    FILE *f = fopen("/etc/resolv.conf","w");
    if(f) {
        fprintf(f,"nameserver 8.8.8.8\n");
        fclose(f);
    }

    mount("devtmpfs", "/dev",  "devtmpfs", 0, NULL);
    mount("proc",     "/proc", "proc",     0, NULL);
    mount("sysfs",    "/sys",  "sysfs",    0, NULL);
    mount("tmpfs",    "/tmp",  "tmpfs",    0, NULL);
    
    int fd = open("/dev/console", O_RDWR);
    dup2(fd, 0); // stdin
    dup2(fd, 1); // stdout
    dup2(fd, 2); // stderr
    if (fd > 2) close(fd);

    setenv("LD_LIBRARY_PATH", "/lib", 1);

    execl("/bin/shell", "shell", NULL);

    
    write(2, "execl failed!\n", 14);
    while(1);
}

/* Won't reboot after a failure because 
* a fail is most of a time an error by 
* me in the code so it's a loop 
* one way or another
*/