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


//p 17  sorting an array 
#include <stdio.h>


void swap(int *a , int *b) {
    int temp = *a;
    *a =*b;
    *b =temp;
}
void sorting(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main() {
    int n;
    int arr[n];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("the original array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sorting(arr, n);

    printf("the sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
//////////////////////////////////////////////
//p18  returning multiple values using pointers 
#include <stdio.h>

void multple(int arr[],  int size) {
    for (int i = 0; i < size; i++) {
        arr[i]= 2 *i +1;
    }

}

int main() {
    int n;
   int arr[n];
    printf("Enter the number of odd num: ");
    scanf("%d", &n);
    multple(arr, n);
    printf("the first %d odd numbers are ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}



