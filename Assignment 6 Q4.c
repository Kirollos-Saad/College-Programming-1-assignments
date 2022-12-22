#include <stdio.h>
#include <stdlib.h>

int substring(char s1[],char s2[])
{
    int i=0,j=0;
    int sub=0;
    while(s1[i]!='\0' && !sub)
    {
        if(s1[i]==s2[j]){
            i++;
            j++;
            if(s2[j]=='\0')
                sub=1;
            }
            else {
            i++;
            if(j!=0)
                j=0;
            }
    }
 return sub;
}
int main()
{
   char s1[30],s2[30];
   printf("Enter string 1 \n");
   gets(s1);
   printf("Enter string 2 \n");
   gets(s2);
   if(substring(s1,s2))
    printf("%s is a substring of %s",s2,s1);
   else
    printf("%s is not a substring of %s",s2,s1);
    return 0;
}
