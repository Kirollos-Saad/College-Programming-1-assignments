#include <stdio.h>
#include <stdlib.h>

void grades(char x,int *gradeA,int *gradeB,int *gradeC,int *gradeF)
{    *gradeA=0;
     *gradeB=0;
     *gradeC=0;
     *gradeF=0;
    while(x!='z'&&x!='Z')
 {
    scanf("%c",&x);
    if(x=='a'||x=='A')
         (*gradeA)++;
    if(x=='b'||x=='B')
         (*gradeB)++;
    if(x=='c'||x=='C')
         (*gradeC)++;
    if(x=='f'||x=='F')
         (*gradeF)++;
 }
}
  int main()
{ char x='x';
  int gradeA,gradeB,gradeC,gradeF;
  printf("Enter your grades and when you finish press z \n ");
  grades(x,&gradeA,&gradeB,&gradeC,&gradeF);
  printf("Number of students who get A is %d \n",gradeA);
  printf("Number of students who get B is %d \n",gradeB);
  printf("Number of students who get C is %d \n",gradeC);
  printf("Number of students who get F is %d \n",gradeF);

    return 0;
}
