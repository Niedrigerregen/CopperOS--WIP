// command that clears the terminal to hide your mess

#include <stdio.h>

int main() {
    printf("\033[H\033[2J\033[3J"); //as i newly discoverd ANSI i'll be featuring iteverywhere possible from now on starting with this escape code
    fflush(stdout);
    return 0;
}