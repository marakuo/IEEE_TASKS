// code for win
/*- Solve Introduction to Arrays Problems: 1, 3, 5, 8, 9, 13, 15, 16, 19.
- Solve Multi-Dimensional Arrays Problems: 24, 27, 30, 37, 40.*/
//P1
#include <stdio.h>

int arrread(int arr[], int size, int index ) {
    if (index >=size) {
        return 0;
    }
    printf("enter the element %d\n", index +1);
    scanf("%d", &arr[index]);
    return arrread(arr, size, index+1);
}
int arrprint(int arr[], int size , int index) {
    if (index >=size) {
        return 0;
    }
    printf("%d\n", arr[index]);

    return arrprint(arr, size, index+1);


}


int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    arrread(arr, n, 0);
    printf("printing array\n");
    arrprint(arr, n, 0);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////

//P3
#include <stdio.h>


int arrsum(int arr[], int size , int index) {
    if (index >=size) {
        return 0;
    }
    return arr[index] + arrsum(arr, size , index + 1);


}
int arrread(int arr[], int size, int index ) {
    if (index >=size) {
        return 0;
    }
    printf("enter the element %d\n", index +1);
    scanf("%d", &arr[index]);
    return arrread(arr, size, index+1);
}


int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    arrread(arr, n, 0);
    int sum = arrsum(arr, n, 0);
    printf("the sum of array = %d" , sum);


    return 0;
}

///////////////////////////////////////////////////////////////////////////////

//p5
#include <stdio.h>
#define n 4
void seclargest (int arr[], int size , int *max, int *secondmax) {
    *max = 0;
    *secondmax =-1;
    for (int i = 0; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] > *secondmax && arr[i]!= *max) {
            *secondmax = arr[i];
        }
    }

}



int main() {
    int arr[n]={1, 2, 3, 4};
    int secondmax, max;
    seclargest (arr, n , &max,  &secondmax) ;
    printf("the 2nd largest element is %d", secondmax);
    

    return 0;
}

///////////////////////////////////////////////////////////////////////////////

//p8

#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int original[n], copy[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &original[i]);
    }
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", original[i]);
    }
    for (int i = 0; i < n; i++) {
        copy[i] = original[i];
    }
    printf("\ncopied array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", copy[i]);
    }



    return 0;
}
///////////////////////////////////////////////////////////////////////////////


//P9

#include <stdio.h>

int main() {
   int arr[50];
    int n , value , position;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        printf("Enter the element%d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the value you aim to insert: ");
    scanf("%d", &value);
    printf("\nEnter the position to insert at: ");
    scanf("%d", &position);


    if (position <0 || position > n+1)
    printf("invalid input");
    else {
        for (int i =n ; i >= position ; i--) {
            arr[i] = arr[i - 1];

        }
    }
    arr[position - 1] = value;
    n++;
    for (int i = 0 ; i < n ; i++) {
        printf("%d ", arr[i]);
    }




    return 0;
}
///////////////////////////////////////////////////////////////////////////////

//P13
#include <stdio.h>

int main() {
   int arr[50];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        printf("Enter the element%d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("the duplicated elements are:");

    for (int i = 0 ; i < n ; i++) {
        int c =1; // each element is duplicated once
        if ( arr[i] !=-1) {
            for (int j =i+1 ; j< n ; j++) {
                if (arr[i] == arr[j]) {
                    c++;
                    arr[j] = -1; // mark as checked
                }

            }
            if (c > 1) {
                printf("%d\n", arr[i]);
                arr[i] = -1;
            }
        }
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////

//P15
#include <stdio.h>

int main() {
    
    int s1, s2;
    int arr1[100],  arr2[100], merged [200];
    printf("Enter number of elements of array 1: ");
    scanf("%d", &s1);
    for (int i = 0; i < s1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter number of elements of array 2: ");
    scanf("%d", &s2);

    for (int i = 0; i < s2; i++) {
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i < s1; i++) {
        merged[i]=arr1[i] ;
    }
    for (int i = 0; i < s2; i++) {
        merged[s1 + i] = arr2[i];
    }

    printf("The merged array is: ");
    for (int i = 0; i < (s1 + s2); i++) {
        printf("%d ", merged[i]);
    }


    return 0;
}
///////////////////////////////////////////////////////////////////////////////
//P16
#include <stdio.h>
#define n 9
void reverse(int arr[], int size) {
    for (int i =size-1; i >=0; i--) {
        printf("%d ", arr[i]);
    }
}
void original (int arr[], int size) {
    for (int i =0 ; i  <size ;i++)
    printf("%d ", arr[i]);

}
int main() {
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    original(arr, n);
    printf("the reversed array is:");
     reverse(arr, n);


    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//  P19

#include <stdio.h>
#define n 9

void descending(int arr[], int size) {

    for (int i = 0; i < size - 1; i++) {
        int max = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        if (max != i) {
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }


    printf("\nThe original array is: ");
    printArray(arr, n);


    descending(arr, n);

    printf("\nThe array in descending order is: ");
    printArray(arr, n);

    return 0;
}


///////////////////////////////////////////////////////////////////////////////
//mult-dimensional array
///////////////////////////////////////////////////////////////////////////////








