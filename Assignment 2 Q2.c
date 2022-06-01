#include <stdio.h>
#include <stdlib.h>

int sum(int n )
{ int i, answer=0;
    for (i=0;i<=n;i++){
        if(i%2==0)
        answer+= i;
       } return answer;
}

int main()
{ int n,result ;
    printf("Enter a number: ");
    scanf("%d",&n);
    result= sum(n);
    printf("The sum of even integers =%d",result);




    return 0;
}
