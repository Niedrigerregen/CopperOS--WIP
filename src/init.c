//turns out it's pretty difficult to make an init = shell system


#include <unistd.h>

int main() {
    execl("/bin/shell", "shell", NULL); //starts the shell
    return 0;
}