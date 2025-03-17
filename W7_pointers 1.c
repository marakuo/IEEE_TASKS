/*Hacker Rank*/
#include <stdio.h>

// function
void func(int *a, int *b) {
    int sum = *a + *b;
    int abs =0;
    if (*a> *b) {
        abs = *a - *b ;
    }
    else if (*b > *a) {
        abs = *b - *a;
    }
    else
        abs =0;
    *a = sum;
    *b = abs;

}

int main() {
    int  x, y;
    printf("Enter x & y :\t");
    scanf("%d%d", &x, &y);
    func(&x, &y);
    printf("x=%d, y=%d\n", x, y);


    return 0;
}


