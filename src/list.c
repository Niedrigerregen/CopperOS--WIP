//command to list files and directories in the current directory

#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *d;
    struct dirent *dir;

    const char *path = "."; // Standard: aktuelles Verzeichnis

    if (argc > 1) {
        path = argv[1]; // optionales Argument: Verzeichnis
    }

    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    } else {
        perror("list");
        return 1;
    }

    return 0;
}