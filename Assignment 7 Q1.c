#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num;
    int denom;
} FRAC;
int gcd(int x,int y)
{
    if(y!=0)
        return gcd(y,x%y);
    else return x;
}
int lcm (int x, int y)
{ int i;
  i=x;
   while(x)
   {
       if (x%y==0)
        return x;
       else
        x+=i;
   }
}

FRAC Multiply_fractions (FRAC n,FRAC m)
{
    FRAC x,result;
    x.denom= ( n.denom* m.denom);
    x.num= ( n.num* m.num);
    result.num= x.num/gcd(x.num,x.denom);
    result.denom= x.denom/gcd(x.num,x.denom);
   return result;
}
FRAC Divide_fractions (FRAC n,FRAC m)
{
    FRAC x,result;
    x.num= n.num*m.denom;
    x.denom= n.denom*m.num;
    result.num= x.num/gcd(x.num,x.denom);
    result.denom= x.denom/gcd(x.num,x.denom);
    return result;
}
FRAC Add_fractions (FRAC n,FRAC m)
{
    FRAC x,result;
    x.denom= lcm( n.denom , m.denom);
    n.num*= (1.0*x.denom/n.denom);
    m.num*= (1.0*x.denom/m.denom);
    x.num= n.num + m.num;
    result.num= x.num/gcd(x.num,x.denom);
    result.denom= x.denom/gcd(x.num,x.denom);
   return result;
}
int main()
{ FRAC n,m;
   FRAC x;
  printf("Enter fraction 1 \n");
  scanf("%d/%d",& n.num,& n.denom);
  printf("Enter fraction 2 \n");
  scanf("%d/%d",& m.num,& m.denom);
  if (n.denom==0 || m.denom==0 )
  printf(" Undefined ");
  else
  {
  x= Multiply_fractions ( n, m);
  printf("Multiplication = \n %d / %d \n",x.num,x.denom);
  x= Divide_fractions ( n, m);
  printf("Division = \n %d / %d \n",x.num,x.denom);
  x= Add_fractions ( n, m);
  printf("Addition = \n %d / %d",x.num,x.denom);
  }
    return 0;
}
