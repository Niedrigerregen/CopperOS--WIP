//math program for basic math operations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void math_operations() { //to be honest this function looks like it's straight out of an 8th Grade IT class period but do it better i guess
    char operation[10];
    double num1, num2;

    printf("Enter the operation (add, sub, mul, div): ");
    scanf("%s", operation);

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    if (strcmp(operation, "add") == 0) {
        printf("Result: %.2lf\n", num1 + num2);
    } else if (strcmp(operation, "sub") == 0) {
        printf("Result: %.2lf\n", num1 - num2);
    } else if (strcmp(operation, "mul") == 0) {
        printf("Result: %.2lf\n", num1 * num2);
    } else if (strcmp(operation, "div") == 0) {
        if (num2 != 0) {
            printf("Result: %.2lf\n", num1 / num2);
        } else {
            printf("Error: Division by zero is not allowed.\n");
        }
    } else {
        printf("Invalid operation. Please try again.\n");
    }
}