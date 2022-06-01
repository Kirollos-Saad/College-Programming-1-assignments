#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
  float real;
  float img ;
} complex;
complex add_complex (complex a, complex b)
{
    complex c;
    c.real=a.real+b.real ;
    c.img=a.img+b.img ;
    return c;
}
 void print_complex (complex a)
 {
   printf("The complex number is \n %0.2f+%0.2fi \n",a.real,a.img);
 }
 complex read_complex ()
 { complex a;
   printf("Enter the complex number in the form of a+bi \n");
   scanf("%f+%fi",&a.real,&a.img);
   return a;
 }
 int compare_complex(complex a, complex b)
 { int x1,x2;
   x1= sqrt(pow(a.real,2)+ pow(a.img,2));
   x2= sqrt(pow(b.real,2)+ pow(b.img,2));
   if(x1>x2)
    return 1;
   else if (x1<x2)
    return -1;
   else
    return 0;
 }
int main()
{ complex a,b,c,r1,r2,compare ;
  a= read_complex();
  b= read_complex();
  c= read_complex();
  print_complex(a);
  print_complex(b);
  print_complex(c);
  r1= add_complex(a,b);
  r2= add_complex(r1,c);
  printf("Result of addition= \n %0.2f+%0.2fi \n",r2.real,r2.img);
  if(compare_complex(a,b)==1 && compare_complex(a,c)==1)
  printf("The complex with higher magnitude is \n %0.2f+%0.2fi",a.real,a.img);
  else if ((compare_complex(b,a)==1 && compare_complex(b,c)==1))
  printf("The complex with higher magnitude is \n %0.2f+%0.2fi",b.real,b.img);
  else
  printf("The complex with higher magnitude is \n %0.2f+%0.2fi",c.real,c.img);
  return 0;
}
