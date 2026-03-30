// Gives out a random quote from the Fight Club in quotes.txt because i like RNGs 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *file;
char quote[256];

int main() {
    file = fopen("data/quotes.txt", "r"); //opens the file by looking through the path
    if (file == NULL) {
        printf("Could not open quotes.txt\n");
        return 1;
    }

    srand(time(NULL));
    int random_line = rand() % 69; //there are 69 quotes in the file, so we get a random number between 0 and 68 because computers count from 0 because hell yeah

    for (int i = 0; i <= random_line; i++) {
        fgets(quote, sizeof(quote), file);
    }

    printf("%s\n", quote);
    fclose(file);
    return 0;
}