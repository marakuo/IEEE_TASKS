#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    float dis, r1, r2, imaginary;


    // Input coefficients of the quadratic equation
    printf("Enter the constants of the quadratic equation (a, b, c): ");
    scanf("%d%d%d", &a, &b, &c);
    dis = (b * b) - (4 * a * c);
    switch (dis>0) {
        case 1:
            r1 = (-b + sqrt(dis)) / (2 * a);
            r2 = (b - sqrt(dis)) / (2 * a);
            printf("Two  roots: %.2f and %.2f\n", r1, r2);
        break;
        case 0:
            switch (dis<0) {
                case 1:
                    r1 = r2 = -b / (2 * a);
                imaginary = sqrt(-dis) / (2 * a);
                printf("Two complex roots: %.2f + i%.2f and %.2f - i%.2f\n", r1, imaginary, r2, imaginary);
                    break;
                case 0:
                    r1 = r2 = -b / (2 * a);
                printf("One real root (repeated): %.2f\n", r1);
                break;

            }

    }



    return 0;
}
