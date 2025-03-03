//                                                                        *************CODE FOR WIN *************
// P1
#include <stdio.h>
int cube(int n) {

    return n*n*n;
}


int main() {
    int x, num;
    printf("enter the number: ");
    scanf("%d", &x);
    num = cube(x);
    printf("the cube of the number is %d", num);


    return 0;
}

_____________________________________________________________
//  P2
#include <stdio.h>
   double area(double radius) {
        float pi =3.14;
      return (pi * radius * radius);
  }
   double circumference(double radius) {
      float pi =3.14;
      return (2*pi * radius );
  }
  double diamter(double radius) {

      return (2* radius );
  }

int main() {
       float radius;
       printf("Enter radius: ");
       scanf("%f", &radius);
       double A = area(radius);
       printf("The area of the circle is: %f\n", A);
       double circum = circumference(radius);
       printf("The circumference of the circle is: %f\n", circum);
       double diameter = diamter(radius);
       printf("The diameter of the circle is: %f\n", diameter);



    return 0;
}



_____________________________________________________________

//P3

#include <stdio.h>
int max(int a, int b) {
    if (a > b) return a;
    else return b;

}
int min(int a, int b) {
    if (a < b) return a;
    else return a;

}



int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int maximum = max(a, b);
    printf("The maximum number is: %d\n", maximum);
    int minimum = min(a, b);
    printf("The minimum number is: %d\n", minimum);




    return 0;
}


_____________________________________________________________
// P6

#include <stdio.h>

int isprime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }
    return 1; 

void find(int num1, int num2) {
    printf("The prime numbers between %d and %d are: ", num1, num2);

    for (int i = num1; i <= num2; i++) {
        if (isprime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    
    if (num1 > num2) {
        printf("Invalid range! The first number should be smaller than the second.\n");
    } else {
        find(num1, num2);
    }

    return 0;
}

____________________________________________________________

//p8
#include <stdio.h>
#include <math.h>


int armstrong(int num) {
    int newnum, digits, lastdigit, sum = 0;
    
    newnum = num;
    digits = log10(num) + 1;  

    while (newnum > 0) {
        lastdigit = newnum % 10; 
        sum += pow(lastdigit, digits); 
        newnum /= 10; 
    }

    return (sum == num); 
}

void findarmstrong(int start, int end) {
    printf("Armstrong numbers between %d and %d are: ", start, end);

    for (int i = start; i <= end; i++) {
        if (armstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int num1, num2;

    printf("Enter the start and end numbers: ");
    scanf("%d %d", &num1, &num2);

    findarmstrong(num1, num2);

    return 0;
}
_____________________________________________________________



//p12
#include<stdio.h>
int oddeven(int start, int end) {
    if (start>end) {
        return 0;
    }
    if (start % 2 == 0) {
        printf("Even: %d\n", start);
    } else {
        printf("Odd: %d\n", start);
    }
    oddeven(start+1, end);

}
int main() {
    int start, end;
    printf("Enter start and end: ");
    scanf("%d %d", &start, &end);
    printf("Numbers between %d and %d:\n", start, end);
    oddeven(start, end);


    return 0;
}
_____________________________________________________________
//P16 
#include <stdio.h>


int reverse(int num, int rev) {
    if (num == 0) {
        return rev;
    }
    return reverse(num / 10, rev * 10 + num % 10);
}


int isPalindrome(int num) {
    return num == reverse(num, 0);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPalindrome(num)) {
        printf("%d is a palindrome number.\n", num);
    } else {
        printf("%d is not a palindrome number.\n", num);
    }

    return 0;
}

_____________________________________________________________
//P17
#include <stdio.h>


int sumdigits(int num) {
    if (num == 0) {
        return 0;
    }
    return ((num % 10) + sumdigits(num / 10));

}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("The sum of digits is %d", sumdigits(num));

    return 0;
}

_____________________________________________________________
//P18

#include <stdio.h>


int fact(int num) {
    if (num <= 0) {
        return 1;
    }
    return  num * fact(num-1);

}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("The fact  of number is %d", fact(num));

    return 0;
}


_____________________________________________________________

 //                                                                    *************hacker rank *************

// P1
#include <stdio.h>


int findterm(int a, int b, int c, int n) {
    if (n == 1) return a;
    if (n == 2) return b;
    if (n == 3) return c;
    return findterm(a, b, c, n - 1) + findterm(a, b, c, n - 2) + findterm(a, b, c, n - 3);
}

int main() {
    int a, b, c, n;


    printf("Enter the first three terms (a, b, c): ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Enter the value of n: ");
    scanf("%d", &n);


    printf("The %dth term of the series is: %d\n", n, findterm(a, b, c, n));

    return 0;
}
________________________________________________
//P2
#include <stdio.h>

void calculateSum(int marks[], int size) {
    int boys = 0, girls = 0;

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            boysSum += *(marks + i);  
        } else {
            girlsSum += *(marks + i); 
        }
    }

    printf("Sum of boys' marks: %d\n", boys);
    printf("Sum of girls' marks: %d\n", girls);
}

int main() {
    int marks[] = {1, 2, 3, 4, 5, 6};  
    int size = sizeof(marks) / sizeof(marks[0]);

    calculateSum(marks, size);

    return 0;
}
