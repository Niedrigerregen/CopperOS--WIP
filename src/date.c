#include <stdio.h>
#include <time.h>


void show_date() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char buffer[26];
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Current date and time: %s\n", buffer);
}

int main() {
    show_date();
    return 0;
}
