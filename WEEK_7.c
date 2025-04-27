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

//----------------------------------------------------------------//


//code for win 
//P5
#include <stdio.h>

int main() {
    int arr1[] = {10, -1, 100, 90, 87, 0, 15, 10, 20, 30};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[size]; 

    
    int *p1 = arr1;
    int *p2 = arr2;

    for (int i = 0; i < size; i++) {
        *(p2 + i) = *(p1 + i);
    }

    
    printf("The Copied array is : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }

    return 0;
}

//----------------------------------------------------------------//

//P6
#include <stdio.h>
#define N 10 // macro

// Function to swap two arrays
void swap(int *a, int *b) {
    for (int i = 0; i < N; i++) {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

int main() {
    int arr1[N], arr2[N];

    // Input values into arr1
    printf("Enter %d elements for array 1:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input values into arr2
    printf("Enter %d elements for array 2:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr2[i]);
    }

    // Print original arrays
    printf("\nBefore swapping:\n");
    printf("Array 1: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\nArray 2: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Swap arrays
    swap(arr1, arr2);

    // Print swapped arrays
    printf("\nAfter swapping:\n");
    printf("Array 1: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\nArray 2: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}

//----------------------------------------------------------------//


//P7
#include <stdio.h>

int main() {
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ptr = a; 

    // Print original order 
    printf("Original order:\n");
    for (int i = 0; i < 9; i++) {
        printf("%d\n", *(ptr + i));  
    }

    printf("________________________\n");

    // Print reversed order 
    printf("Reversed order:\n");
    for (int i = 8; i >= 0; i--) {
        printf("%d\n", *(ptr + i));  
    }

    return 0;
}


//----------------------------------------------------------------//

// p8

#include <stdio.h>

void search(int *arr, int size, int key) {
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (*(arr + i) == key) {
            printf("Element %d found at index %d.\n", key, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", key);
    }
}

int main() {
    int n, key;


    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];


    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }


    printf("Enter the element to search: ");
    scanf("%d", &key);

    search(arr, n, key);

    return 0;
}



//---------------------------------------//

//p11

#include <stdio.h>

#define MAX 10  // Define max size for simplicity

void multiply(int (*A)[MAX], int (*B)[MAX], int (*C)[MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            *(*(C + i) + j) = 0;  // Initialize result matrix
            for (int k = 0; k < c1; k++) {
                *(*(C + i) + j) += *(*(A + i) + k) * *(*(B + k) + j);
            }
        }
    }
}

void inputMatrix(int (*mat)[MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", (*(mat + i) + j));
}

void printMatrix(int (*mat)[MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", *(*(mat + i) + j));
        printf("\n");
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int r1, c1, r2, c2;

    printf("Enter rows and cols of first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and cols of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Multiplication not possible!\n");
        return 1;
    }

    printf("Enter elements of first matrix:\n");
    inputMatrix(A, r1, c1);

    printf("Enter elements of second matrix:\n");
    inputMatrix(B, r2, c2);

    multiply(A, B, C, r1, c1, c2);

    printf("Resultant matrix:\n");
    printMatrix(C, r1, c2);

    return 0;
}

//--------------------------------------------//

//p12 
#include <stdio.h>

int length(char *str) {
    int length = 0;
    while (*str) {
        length++;
        str++;
    }
    return length;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Length of the string: %d\n", length(str));
    return 0;
}

//---------------------------//


 //P 14 
#include <stdio.h>

void concatenate(char *str1, char *str2) {
    while (*str1) 
        str1++;

    while (*str2) { 
        *str1 = *str2;
        str1++;
        str2++;
    }

    *str1 = '\0'; 
}

int main() {
    char str1[100], str2[50];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    concatenate(str1, str2);

    printf("Concatenated String: %s\n", str1);
    return 0;
}

//------------------------------------//

//p16 

#include <stdio.h>

void reverse(char *str) {
    char *end = str;
    char temp;


    while (*end)
        end++;
    end--;


    while (str < end) {
        temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str); 

    reverse(str);

    printf("Reversed String: %s\n", str);
    return 0;
}

