#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Factorial(int j){
    int fact = 1;
    for(int i = 1; i <= j; i++){
        fact *= i;
    }
    return fact;
}
int main(){
        int n, i, j;
        float x, result=0;
        printf("Enter angle in degree: ");
        scanf("%f",&x);
        printf("\nEnter number of terms: ");
        scanf("%d",&n);
        x = x*3.14/180;

        for(i=0; i<n; i++){
            j=2*i+1;
            result += pow(-1,i)*(pow(x,j)/Factorial(j));
        }
        printf("\nResult= %f", result);
    return 0;
}
