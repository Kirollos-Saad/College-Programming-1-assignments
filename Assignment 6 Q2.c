#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void delete (char *str ,char x)
{ int i=0,j=0;

   while(str[i])
   { if(str[j]!=x)
   {
    str[i]=str[j];
     i++;
     j++;
   }
     else
       j++;
   }
}
int main()
{
    char str [20],x;
    printf("Enter your string \n");
    gets(str);
    printf("Enter the character you wan to delete  \n");
    scanf("%c",&x);
    delete(str,x);

    printf("your string after deleting \n%s",str);


    return 0;
}
