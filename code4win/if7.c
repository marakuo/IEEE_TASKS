#include <stdio.h>

int main() {
    char letter;
    printf("Enter a letter: ");
    scanf("%c", &letter);
    if ((letter >='a' && letter <='z') || (letter >='A' && letter <='Z')) {
        printf("%c is an alphabet ", letter);
    }
    else
        printf("%c is not an alphabet", letter);

    return 0;
}
