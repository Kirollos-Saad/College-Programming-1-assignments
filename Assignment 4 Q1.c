#include <stdio.h>
#include <stdlib.h>

int main()
{   int n;
    printf("Enter size of the array");
 scanf("%d",&n);
    int arr[n],i,j,count;
 printf("Array element are \n");
 for(i=0;i<n;i++)
 {
     printf("arr [%d]= ",i);
  scanf("%d",&arr[i]); }

 for(i=0;i<n;i++)
 {  count=0;
    for(j=0;j<n;j++)
    {
      if(arr[i]==arr[j])
       count ++;
    }
     if (count==1)
        printf("Unique elements are a[%d]=%d \n",i,arr[i]);
 }




 return 0;

}
