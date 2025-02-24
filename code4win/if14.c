#include <stdio.h>

int main() {
    int ang1, ang2, ang3;
    printf("Enter the 1st angle:\n");
    scanf("%d", &ang1);
    printf("Enter the 2nd angle:\n ");
    scanf(" %d", &ang2);
    printf("Enter the 3rd angle:\n");
    scanf(" %d", &ang3);

    if ( (ang1+ang2+ang3) ==180) {
       printf("the triangle is valid");

    }
    else {
        printf("the triangle is invalid");
    }

    return 0;
}
