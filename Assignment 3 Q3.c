#include <stdio.h>
#include <stdlib.h>
void marks(float x,float y,float z,int *pass,int *fail,float *totalgpa)
{
    *pass=0;
    *fail=0;
    if(x>=50)
        (*pass)++ ;
    else (*fail)++;
    if(y>=50)
        (*pass)++ ;
    else (*fail)++;
    if(z>=50)
        (*pass)++ ;
    else (*fail)++;
    *totalgpa=((x+y+z)/300)*4;
}

int main()
{ float x,y,z,totalgpa;
  int pass,fail;
  printf("Enter your grades: \n");
  scanf("%f %f %f",&x,&y,&z);
  marks(x,y,z,&pass,&fail,&totalgpa);
  printf("Number of courses that the student passed:%d \n",pass);
  printf("Number of courses that the student failed:%d \n",fail);
  printf("GPA= %f",totalgpa);


    return 0;
}
