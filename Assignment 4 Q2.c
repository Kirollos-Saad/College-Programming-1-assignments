#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    printf("Enter number of students ");
    scanf("%d",&n);
    float arr[n][2],sum=0,avr;
    for(i=0;i<n;i++)
    {
        printf("Enter student ID: \n");
        scanf("%f",&arr[i][0]);
        printf("Enter student score \n ");
        scanf("%f",&arr[i][1]);
        sum+=arr[i][1];
    }
        avr=1.0*(sum/n);
        printf("average= %0.2f \n",avr);
        avr*=0.05;
        for(i=0;i<n;i++)
        {
            printf("Student %0.2f score with the bonus= %0.02f \n",arr[i][0],(arr[i][1]+avr));
        }

        return 0 ;
}

