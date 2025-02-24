#include <stdio.h>


int main() {
    float a, b;
    char operation;
    printf("enter the 2 numbers:\n ");
    scanf("%f %f", &a, &b);
    printf("Enter the operation: ");
    scanf(" %c", &operation);
    switch (operation) {
        case '+':
            printf("%.2f + %.2f = %.2f", a, b, a + b);
        break;
        case '-':
            printf("%.2f - %.2f = %.2f", a, b, a - b);
        break;
        case '*':
            printf("%.2f * %.2f = %.2f", a, b, a * b);
        break;
        case '/':
            printf("%.2f / %.2f = %.2f", a, b, a / b);
        break;

        default:
            printf("Invalid operation");
    }


    return 0;
}
