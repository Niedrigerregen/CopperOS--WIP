// Printf only prints, when the Program is ended or when the buffer is full so we have to flush the buffer for every printf

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char operation[10];
    char buffer[50];
    double num1, num2;

    printf("Enter the operation (add, sub, mul, div): ");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%9s", operation);

    printf("Enter the first number: ");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    num1 = atof(buffer);

    printf("Enter the second number: ");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    num2 = atof(buffer);

    if (strcmp(operation, "add") == 0)
        printf("Result: %.2lf\n", num1 + num2);
    else if (strcmp(operation, "sub") == 0)
        printf("Result: %.2lf\n", num1 - num2);
    else if (strcmp(operation, "mul") == 0)
        printf("Result: %.2lf\n", num1 * num2);
    else if (strcmp(operation, "div") == 0) {
        if (num2 != 0)
            printf("Result: %.2lf\n", num1 / num2);
        else
            printf("Error: Division by zero\n");
    } else {
        printf("Invalid operation.\n");
    }

    return 0;
}