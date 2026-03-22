//command that clears the terminal to hide your mess

#include <stdio.h>
#include <stdlib.h>

int clear_terminal() { // this function now has an int just because i wanted the ascii-logo to loop without a loop! revolutionary!
    system("clear");
    return 0;
}