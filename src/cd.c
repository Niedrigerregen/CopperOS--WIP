//classic cd command for changing directories.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void change_directory(const char *path) {
    if (chdir(path) == 0) {
        printf("Changed directory to: %s\n", path);
    } else {
        perror("Error changing directory");
    }
}