
#include <stdio.h>

int main()
{
    int ph, chem, bio, math, comp;
    int percent;


    printf("Enter the marks of the 5 subjects: ");
    scanf("%d%d%d%d%d", &ph, &chem, &bio, &math, &comp);



    percent = (ph + chem + bio + math + comp) / 5;
    printf("percentage = %d\n", percent);



    if(percent >= 90)
    {
        printf("Grade A");
    }
    else if(percent >= 80)
    {
        printf("Grade B");
    }
    else if(percent >= 70)
    {
        printf("Grade C");
    }
    else if(percent >= 60)
    {
        printf("Grade D");
    }
    else if(percent >= 40)
    {
        printf("Grade E");
    }
    else
    {
        printf("Grade F");
    }

    return 0;
}
