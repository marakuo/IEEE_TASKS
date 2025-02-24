#include <stdio.h>

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    if (num % 5==0 && num % 11==0) {
        printf("%d is divisible by 11 and 5", num);

    }
    else {
        printf(" %d is not divisible by 11 and 5 ", num);
    }


    return 0;
}
