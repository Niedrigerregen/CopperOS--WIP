#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "cd.h"

#define MAX_CMD 256

   void print_logo_content(void) {

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

    void print_logo(void) {

    static int firstTime = 1; // basically all these new additions are just to fix the logo printing after every command and literally forgetting the command

     if (firstTime) {
        firstTime = 0;
        print_logo_content();            
    } 
}

void print_logo_force(void) {
    print_logo_content();
}

int main() {
    char command[MAX_CMD];

    print_logo();
    
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
                execl("/bin/clear", "clear", NULL);
                perror("exec failed");
                exit(1);
            } else if (pid > 0) {
                wait(NULL);
                print_logo_force();
            } else {
                perror("fork failed");
            }
            continue;
        }

        if (strcmp(command, "help") == 0) {
    printf("Available commands:\n");
    printf("help - Show this cool help message\n");
    printf("cd - Change directory\n"); // not really effective in a live OS but it can stay for when i turn it into an ... on demand OS?
    printf("shutdown - Shutdown the system\n");
    printf("clear - Clear the terminal screen\n");
    printf("echo - Echoes the input back to the terminal\n");
    printf("list - List files in the current directory\n");
    printf("math - Perform basic math operations\n");
    printf("more commands in the future...\n");
    continue;
} 

char *args[MAX_CMD];
char cmd_copy[MAX_CMD];                                
strncpy(cmd_copy, command, MAX_CMD);           
                                                  
int i = 0;                                  
args[i] = strtok(cmd_copy, " ");
while (args[i] != NULL) {
    args[++i] = strtok(NULL, " ");
}

char bin_path[MAX_CMD];
snprintf(bin_path, sizeof(bin_path), "/bin/%s", args[0]); 
args[0] = bin_path;

pid_t pid = fork();
if (pid == 0) {
    execvp(bin_path, args);
    perror("exec failed");
    _exit(1);
} else if (pid > 0) {
    wait(NULL);
} else {
    perror("fork failed");
}
    }

    return 0;
}