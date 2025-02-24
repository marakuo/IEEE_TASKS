/**
 * C program to find power of any number using for loop
 */

#include <stdio.h>

int main()
{
    int base , power;
    long long result=1 ;
    printf("enter the base: ");
    scanf("%d", &base);
    printf("enter the power: ");
    scanf(" %d", &power);
    for(int i=1 ; i<=power ;i++){
        result = result *base;
        
    }
    printf(" %d ^ %d = %lld", base, power, result);
    
    return 0;
}
