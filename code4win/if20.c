
#include <stdio.h>

int main()
{
    int sal;
    printf("Enter the basic salary: ");
    scanf("%d",&sal);
    if(sal<= 10000) {
        printf(" HRA = 20%%, DA = 80%% ");
    }
    else if (2000>sal>= 10000) {

        printf(" HRA = 25%%, DA = 90%%");

    }
    else if (sal >= 20001) {

        printf(" HRA = 30%%, DA = 95%% ");

    }
    return 0;
}
