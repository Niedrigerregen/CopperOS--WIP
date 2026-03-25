//yep... another "fix"... but i promise this time will be the last one!

#include <unistd.h>
#include <sys/mount.h>
#include <fcntl.h>

int main() {
    
    mount("devtmpfs", "/dev",  "devtmpfs", 0, NULL);
    mount("proc",     "/proc", "proc",     0, NULL);
    mount("sysfs",    "/sys",  "sysfs",    0, NULL);

    
    int fd = open("/dev/console", O_RDWR);
    dup2(fd, 0); // stdin
    dup2(fd, 1); // stdout
    dup2(fd, 2); // stderr
    if (fd > 2) close(fd);

    execl("/bin/shell", "shell", NULL);

    
    write(2, "execl failed!\n", 14); //now even says that it's dying instead of just not saying it!
    while(1);
}