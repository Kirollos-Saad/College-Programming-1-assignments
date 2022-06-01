#include <stdio.h>
#include <stdlib.h>

int sumof5(int n)
{
    if(n>=1&& n%5==0){

    return n+sumof5(n-1);
    }

    else if (n%5!=0)
    return sumof5(n-1);

}

int main()
{ int num ;
  printf("Enter a number ");
  scanf("%d",&num);
  printf("Result =  %d ",sumof5(num));



    return 0;
}
