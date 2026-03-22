//for the first release, i will just make a really minimal TTY-like terminal like i know from MS-DOS because nobody builds a rocketship after they discovered fire you know?
//also i heard socrates once said "maybe you're not meant to build a GUI in C. Especially if you just watched a crash course on C programming a few hours ago" 
// This Code will be PID-1 and at the same time be Shell but i won't name it shell.c because i am the god of this OS and i make the rules here

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "cd.h" 

#define MAX_CMD 256 //character limit because memory is now worth gold according to C


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

int main() {
    char command[MAX_CMD];

    while (1) {
        printf("$> ");
        if (!fgets(command, sizeof(command), stdin)) continue;

        
        command[strcspn(command, "\n")] = 0;

        //cd is now built-in instead of being a cool command like echo is - you never stop learning that your logic is completely false while you're mid project 
        if (strncmp(command, "cd ", 3) == 0) {
            change_directory(command + 3);
            continue;

    if (strcmp(command, "clear") == 0) {
        pid_t pid = fork();

        if (pid == 0) {
        execlp("clear", "clear", NULL);
        perror("exec failed");
        exit(1);}
         
        else {
        wait(NULL);
        print_logo(); //the non-buggy version of my dream of permanently staying Ascii-logo
    }
}
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
    else {
    pid_t pid = fork();
    if (pid == 0) {
        execlp(command, command, NULL);
        printf("Unknown command: %s\n", command);
        exit(1);
    } else {
        wait(NULL);
    }
}
        pid_t pid = fork();
        if (pid == 0) {
            
            execlp(command, command, NULL);
            perror("exec failed");
            exit(1);
        } else if (pid > 0) {
            
            wait(NULL);
        } else {
            perror("fork failed");
        }
    }

    return 0;
}