//command to list files and directories in the current directory

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void list_files() {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    } else {
        perror("something went wrong while listing");
    }
}