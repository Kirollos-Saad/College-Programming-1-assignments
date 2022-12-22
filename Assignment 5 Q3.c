#include <stdio.h>
#include <stdlib.h>

void reverse (int *n1,int *n2 )
{
  int temp;
   temp= *n1;
   *n1=*n2;
   *n2=temp;
}

int main()
{
    int n,i,temp;
    printf("Enter the size of your elements \n");
    scanf("%d",&n);
    int arr[n];
    printf ("Enter your elements \n") ;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Elements before reversing \n");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    for(i=0;i<n/2;i++)
        reverse(arr+i,arr+(n-1-i));


     printf("\nElements after reversing \n");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    return 0;
}
