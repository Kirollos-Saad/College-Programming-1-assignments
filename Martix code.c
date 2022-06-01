#include <stdio.h>
#include <stdlib.h>



int main()
{   int n,m;
    printf("Enter size of the array");
 scanf("%d %d",&n,&m);
    int arr[n][m],i,j,;

 for(i=0;i<n;i++)
 {
   for(j=0;j<m;j++)
     {
      printf("Enter your array a[%d][%d]= ",i,j);
       scanf("%d",&arr[i][j]);
      }

  printf("\n");
 }
 printf("Matrix of %d  %d \n",n,m);
 for(i=0;i<n;i++)
 {
   for(j=0;j<m;j++)
     {
      printf("%d \t ",arr[i][j]);

      }

  printf("\n");
 }






 return 0;

}
