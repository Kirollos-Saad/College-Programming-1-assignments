#include <stdio.h>
#include <stdlib.h>

int count(int n,int m,int a[n][m])
{  int i,j,count=0;
for(i=0;i<n;i++)
 {
   for(j=0;j<m;j++)
     {
      if(isprime(a[i][j]))
        count++;
      }
 }
      return count;
}
int isprime(int x)
{
    int i ;
    for(i=2;i<x;i++)
    {
        if(x%i==0)
            return 0;
           }
            if(x==1) return 0;
            else return 1;

 }
int main()
{
   int n,m,i,j;
    printf("Enter the size of your Elements \n");
  scanf("%d %d",&n,&m);
    int arr[n][m];

 for(i=0;i<n;i++)
 {
   for(j=0;j<m;j++)
     {
      printf("Enter element [%d][%d]= ",i,j);
       scanf("%d",&arr[i][j]);
      }
 }
 printf("Your Elements \n");
 for(i=0;i<n;i++)
 {
   for(j=0;j<m;j++)
     {
      printf("%d \t ",arr[i][j]);

      }
printf("\n");
 }

 printf("Number of prime numbers in your elements= %d ",count(n,m,arr));


    return 0;
}
