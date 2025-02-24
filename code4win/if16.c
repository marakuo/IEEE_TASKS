#include <stdio.h>

int main() {
    int s1, s2, s3;
    printf("Enter the 1st side:\n");
    scanf("%d", &s1);
    printf("Enter the 2nd side:\n ");
    scanf(" %d", &s2);
    printf("Enter the 3rd side:\n");
    scanf(" %d", &s3);


   if (s1+s2<s3 || s2+s3<s1 || s3+s1<s2) {
       printf("invalid dimensions"); //check if it's a triangle or not 
   }
    else {
        if (s1 == s2 && s2 == s3) {
            printf("this is an Equilateral triangle");
        }
        else if (s1 == s2 || s2 == s3 || s3==s1) {
            printf("this is an Isosceles triangle");
        }
        else {
            printf("this is an Escalene triangle");
        }
    }

    return 0;
}
