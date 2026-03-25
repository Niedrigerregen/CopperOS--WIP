//turns out it's pretty difficult to make an init = shell system. Or is it? I forgot to set the console in grub.cfg so maybe that's why it didn't work
//idk man do i look like some coding senior i'm an awkward 14 year old

#include <unistd.h>

int main() {
    execl("/bin/shell", "shell", NULL); //starts the shell
    return 0;
}