//for the first release, i will just make a really minimal TTY-like terminal like i know from MS-DOS because nobody builds a rocketship after they discovered fire you know?
//also i heard socrates once said "maybe you're not meant to build a GUI in C. Especially if you just watched a crash course on C programming a few hours ago" 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cd.h>
#include <clear.h>
#include <echo.h>
#include <shutdown.h>

void print_logo(void) {
    printf("\n");
    printf("  ____                                  ___  ____\n");
    printf(" / ___|___  _ __  _ __   ___ _ __      / _ \\/ ___|\n");
    printf("| |   / _ \\| '_ \\| '_ \\ / _ \\ '__|    | | | \\___ \\\n");
    printf("| |__| (_) | |_) | |_) |  __/ |       | |_| |___) |\n");
    printf(" \\____\\___/| .__/| .__/ \\___|_|        \\___/|____/\n");
    printf("           |_|   |_|\n");
    printf("\n");
}


// function to initialize the terminal
void init_terminal() {
    printf("Welcome to CopperOS!\n");
    printf("Type 'help' for commands\n");
}


int main() {
    init_terminal();

    // loop to keep the terminal open similar to tkinter's root.mainloop(). why did i tell you that tkinter part? i don't know.
    while (1) {
        char command[100];
        printf("$> "); // i don't know if the dollar sign is placed correctly but i have seen it in ubuntu based terminals and it looks cool
        fgets(command, sizeof(command), stdin);

        // remove newline character from the end of the command
        command[strcspn(command, "\n")] = 0;

        // help command but it's in the init.c file. but why? because i want to. make me,(the coolest guy ever) change it. 
        if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("help - Show this help message\n");
            printf("cd - Change directory\n");
            printf("shutdown - shutdown the system\n");
            printf("clear - Clear the terminal screen\n");
            printf("echo - Echoes the input back to the terminal\n");
            printf("more commands in the future...\n");
            }
        else {
            printf("Unknown command: %s\n", command);
            }

        if (clear_terminal() == 0) {
        print_logo();
    } 
    }

    return 0;
}

