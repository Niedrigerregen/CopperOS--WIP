//newly added shell as it turned to be a not-so-great idea to set init = shell (basically it eternally stays in the Kernel boot logs)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "cd.h"

#define MAX_CMD 256

void print_logo(void) {
    printf("\n");
    printf("   /$$$$$$                                                             /$$$$$$   /$$$$$$ \n");
    printf("  /$$__  $$                                                           /$$__  $$ /$$__  $$\n");
    printf(" | $$  \\__/  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$         | $$  \\ $$| $$  \\__/\n");
    printf(" | $$       /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$ /$$$$$$| $$  | $$|  $$$$$$ \n");
    printf(" | $$      | $$  \\ $$| $$  \\ $$| $$  \\ $$| $$$$$$$$| $$  \\__/|______/| $$  | $$ \\____  $$\n");
    printf(" | $$    $$| $$  | $$| $$  | $$| $$  | $$| $$_____/| $$              | $$  | $$ /$$  \\ $$\n");
    printf(" |  $$$$$$/|  $$$$$$/| $$$$$$$/| $$$$$$$/|  $$$$$$$| $$              |  $$$$$$/|  $$$$$$/\n");
    printf("  \\______/  \\______/ | $$____/ | $$____/  \\_______/|__/               \\______/  \\______/ \n");
    printf("                     | $$      | $$                                                       \n");
    printf("                     | $$      | $$                                                       \n");
    printf("                     |__/      |__/                                                       \n");
    printf("\n");
}



void change_directory(const char *path);
void print_logo(void);

int main() {
    char command[MAX_CMD];

    while (1) {
        printf("$> ");
        if (!fgets(command, sizeof(command), stdin))
            continue;

        
        command[strcspn(command, "\n")] = 0;

        
        if (strncmp(command, "cd ", 3) == 0) {
            change_directory(command + 3);
            continue;
        }

        
        if (strcmp(command, "clear") == 0) {
            pid_t pid = fork();
            if (pid == 0) {
                execlp("clear", "clear", NULL);
                perror("exec failed");
                exit(1);
            } else if (pid > 0) {
                wait(NULL);
                print_logo();
            } else {
                perror("fork failed");
            }
            continue;
        }

        if (strcmp(command, "help") == 0) {
    printf("Available commands:\n");
    printf("help - Show this cool help message\n");
    printf("cd - Change directory of a file\n");
    printf("shutdown - Shutdown the system\n");
    printf("clear - Clear the terminal screen\n");
    printf("echo - Echoes the input back to the terminal\n");
    printf("list - List files in the current directory\n");
    printf("math - Perform basic math operations\n");
    printf("more commands in the future...\n");
    continue;
} 

        pid_t pid = fork();

        if (pid == 0) {
        char *args[] = {"/bin/sh", "-c", command, NULL};
        execvp(args[0], args);
        perror("exec failed");
        _exit(1);

}       else if (pid > 0) {
        wait(NULL);

}       else {
        perror("fork failed");
}
    }

    return 0;
}