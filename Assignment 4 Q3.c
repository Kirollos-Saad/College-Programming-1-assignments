#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j;
    printf("Please enter number of students : \n");
    scanf("%d",&n);
    printf("Please enter number of courses : \n");
    scanf("%d",&m);
    float arr[n][m];
     float sum[n],sumCourses[m];
    for(int i=0; i<n;i++)
    {
        printf("please enter grades for student no %d \n",i+1);
        for (int j= 0; j < m; j++)
        {
            scanf("%f",&arr[i][j]);
            sum[i]+=arr[i][j];
        }

    }
    for(int i=0; i<n; i++)
    {
        printf("avgerage of student number %d = %.2f \n",i+1,sum[i]/m);
    }
    for(int i=0; i<n;i++)
    {
        for (int j= 0; j< m; j++)
        {
            sumCourses[j]+= arr[i][j];
        }
    }
    for(int j=0; j<m; j++)
    {
        printf("avgerage of course no %d = %.2f \n",j+1,sumCourses[j]/n);
    }
 return 0;
 }
