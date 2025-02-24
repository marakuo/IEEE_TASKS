#include <stdio.h>

int main() {
    int month;
    printf("Enter the month number: ");
    scanf("%d", &month);
    if (month < 1 || month > 12) {
       printf("invalid input");

    }
    else {
        if (month ==2)
            printf("month num %d has 29 days", month);
        else if (month == 4 || month == 6 || month == 9 || month == 11  ) {
            printf("the month num %d has 30 days", month);
        }
        else {
            printf("the month num %d has 31 days", month);
        }
    }

    return 0;
}
