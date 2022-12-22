#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void replacestring(char s[][30],int n,char *oldstr,char *newstr)
{ int i;
    for(i=0;i<n;i++)
    { if(strcmp(s[i],oldstr)==0)
       strcpy(s[i],newstr);

    }
}
int main()
{
    int n,i=0;
    printf("Enter number of names ");
    scanf("%d",&n);
    char s[n][30],oldstr[20],newstr[20];
    printf("Enter the names \n");
    for(i=0;i<n;i++)
     {scanf("%s",s[i]);}

    printf("Enter old string\n");
    scanf("%s",oldstr);
    printf("Enter new string\n");
    scanf("%s",newstr);
    replacestring(s,n,oldstr,newstr);
    printf("The names after modification \n");
    for(i=0;i<n;i++)
    {

     printf("name %d is %s \n",i+1,s[i]);

    }


    return 0;
}
