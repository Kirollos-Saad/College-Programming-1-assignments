#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int convertToDecimal(int x){
    int i=0, n , t=x , result=0;
    while(t!=0){
        n = t%10;
        t = t/10;
        result += pow(2,i)*n;
        i++;


    }
        return result;
}


int main()
{
    int num, result;
    printf("Enter a binary number to convert: ");
    scanf("%d",&num);
    result = convertToDecimal(num);
    printf("result = %d", result);

}
