#include <stdio.h>
#include <stdlib.h>

float factorial(int x){
    if(x<2)
    return 1;
    else
    return factorial(x-1)*x;
}

int main()
{
    int i;
    float n, sum=0;
    printf("Enter N: ");
    scanf("%f",&n);
    for(i=1;i<=n;i++){
        sum += i/factorial(i+1);}

    printf("Result equal: %f",sum);

    return 0;
}
