#include <stdio.h>
#include <stdlib.h>

void itoaa(int x, char str[])
{
    int i=0,c=0,z;
    z=x;
    if(x<0)
    {
      str[0]='-';
      x *=-1;
    }
    while(z)
    {
      z /=10;
      c++;
    }


   //i=log10(x)+1;


    while(x)
    {
      str[c]= x%10 + '0';
       c--;
       x /=10;
    }

}

int main()
{
    char str [20];
    int x;
    printf("Enter a number \n");
    scanf("%d",&x);
    itoaa(x,str);
    printf(" %s ",str);


    return 0;
}
