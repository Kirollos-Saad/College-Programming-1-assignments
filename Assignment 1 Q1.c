#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, num, rem,sum=0,count=0;
    printf("please enter a number: ");
    scanf("%d",&num);

    x=num;
    while(x!=0){
        rem = x%10;
        x=x/10;
        count++;}

    x=num;
    while(x!=0){
        rem= x%10;
        x=x/10;
        sum += pow(rem,count);

    }
    if (sum==num){
        printf("\nThis number is an Armstrong Number");
    }
    else {printf("\nThis number is Not an Armstrong Number");}



    return 0;
}
