#include <stdio.h>
#include <stdlib.h>
int count=0;
int countthedigit(int n)
{
    if(n>0){
    count+=1;
    return countthedigit(n/10);
    }

    else
    return count;

}

int main()
{ int num ;
  printf("Enter a number ");
  scanf("%d",&num);
  printf("The number of digits in the number is: %d ",countthedigit(num));



    return 0;
}
