#include <stdio.h>
#include <stdlib.h>

int main()
{ int m,n,i,j,sum=0;
  float average=0;
 printf("Enter number of rows and columns \n");
 scanf("%d %d",&m,&n);
  int arr[m][n];
  printf("Enter your elements \n");
 for(i=0;i<m;i++){
    for(j=0;j<n;j++)
    {
        scanf("%d",&arr[i][j]);

     }


                 }
    for(i=0;i<m;i++){
    sum=0;
    for(j=0;j<n;j++)
    {
        sum+= arr[i][j];
        average+= arr[i][j];
     }
      printf("Sum of elements of row %d = %d \n",i,sum);
    }
      printf("Average of all elements= %0.2f ",average/(n*m));


    return 0;
}
