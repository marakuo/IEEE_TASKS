
#include <stdio.h>

int main() {
    int num, product = 1, digit;


    printf("Enter a number: ");
    scanf("%d", &num);


    if (num == 0) {
        printf("Product of digits: 0\n");
        return 0;
    }

    while (num > 0) {
        digit = num % 10; // Extract last digit
        product *= digit; // Multiply with product
        num /= 10; // Remove last digit
    }

    printf("Product of digits: %d\n", product);

    return 0;
}
