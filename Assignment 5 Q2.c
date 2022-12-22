#include <stdio.h>
#include <stdlib.h>

void sort(int *a,int n)
{  int i,j,temp;
    for(i=0;i<n;i++)
    { for(j=i+1;j<n;j++)
      {
        if(*(a+i)< *(a+j))
        {
            temp= *(a+i);
            *(a+i)=*(a+j);
            *(a+j)=temp;
        }
      }

    }

}
int main()
{ int n,i;
  printf("Enter size of your elements");
  scanf("%d",&n);
  int arr[n];
  printf("Enter your elements ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  sort(arr,n);
  printf("Elemnts in descending order \n");
  for(i=0;i<n;i++)
  {
    printf( "%d \t",arr[i]);
  }



    return 0;
}
