//HackerRank
#include <stdio.h>
//function

void assign(int * a, int *b) {
    int temp = *a;
    *a= *b + *a;
     if (temp > *b)
     *b = temp - *b;
     else 
     *b = *b -temp;
    }

int main() {
     int x, y;
    scanf("%d %d", &x, &y);
    assign(&x, &y);
    printf("%d\n%d\n", x, y);

    return 0;
}


/* code for win */

//_________________________________________________________//

//  p17
#include <stdio.h>

float  fun(int * p, int *t, float *r) {
    float si = (*p * *t * *r) /100;
    return si;
    }


int main() {
    int p, t;
    float r;
    scanf("%d %d %f", &p , &t , &r);
    int *p1 = &p;
    int *p2 = &t;
    float *p3 = &r;
    fun(&p, &t, &r);
    printf("%f\n", fun(p1, p2, p3));

    return 0;
}
 //______________________________________________________//

//P18

#include <stdio.h>

float  fun(int * p, int *t, float *r) {
    float base = 1 + (*r / 100);
    float result = 1;

    for (int i = 0; i < *t; i++) {
        result *= base;
    }
    float ci = (*p) * result;

    return ci ;
    }


int main() {
    int p, t;
    float r;
    scanf("%d %d %f", &p , &t , &r);
    int *p1 = &p;
    int *p2 = &t;
    float *p3 = &r;
    fun(&p, &t, &r);
    printf("%f\n", fun(p1, p2, p3));


    return 0;
}
