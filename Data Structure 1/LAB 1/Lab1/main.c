#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 100

typedef struct {
 int items[SIZE];
 int top;
  } stack ;

stack *initialize ()
 { stack *s=malloc(sizeof(stack));
 s->top=0;
 return s;
 }

 void push (stack *s,int x)
 { s->items[s->top]=x;
     s->top++;
 }

 int pop (stack *s)
{ int x;
  s->top--; x= s->items[s->top];
  return x;
}

int isfull (stack *s)
{ if( s->top== SIZE ) return 1;
  else
    return 0;
}

int isempty (stack *s)
{
    if(s->top==0) return 1;
  else
    return 0;
}
int peek(stack *s)
{
  return s->items[s->top - 1];
}
void display (stack *s)
{ stack *temp=initialize();
  while(!isempty(s) )
 {
   int x=pop(s);
   printf("%d \n",x);
   push(temp,x);
 }
 while(!isempty(temp))
 {
     push(s,pop(temp));
 }

}
void reverse_string(stack *string)
{ int i; char str[20]; stack *temp=initialize();
    printf("Enter your string \n"); getchar();
    gets(str);
    printf("your string is \n ");
    for(i=0;i<strlen(str);i++)
    {
      push(string,str[i]);
      printf("%c \n",str[i]);
      char x=pop(string);
      push(temp,x);

    }
    printf("Reversed string \n");

    while(!isempty(temp))
 {   char c=pop(temp);
     printf("%c \n",c);
     push(string,c);
 }

}
void check_sort(stack *s) //check sorting that the min appears at the top of the stack
{ int sorted=1 ,x; stack *temp=initialize();
 while (!isempty(s))
  { x=pop(s);push(temp,x);
   if(x>peek(s))
    { sorted=0; break;
    }
  }  while(!isempty(temp))
 {
     push(s,pop(temp));
 } if(sorted) printf("Your stack is sorted\n");
  else printf("Your stack is not sorted\n");

}

int isprime(int x)
{

    if(x==0||x==1) return 0;
    int i,root;
    root = floor(sqrt(x)); // truncating the number
    for(i=2;i<root+1;i++){

        if(x%i==0) return 0;

    }

    return 1;
}

void delete_nonprime(stack *s)
{ stack *temp=initialize(); stack *copy=initialize();
  int x;
  while(!isempty(s))
  { x=pop(s);
    if(isprime(x)) {push(temp,x);}
    else  push (copy,x);
  } printf("Your stack after deleting non-prime numbers \n");
  display(temp);

  while(!isempty(temp) && !isempty(copy))
 {   push(s,pop(copy));
     push(s,pop(temp));
 } printf("Your original stack \n");display(s);
}
 void sort(stack *s) // sorting that the min appears at the top of the stack
{ stack *temp=initialize(); int x,y;
  while(!isempty(s))
  { x=pop(s);
  while (!isempty(temp)&& (peek(temp)>x))
  { y=pop(temp);
    push(s,y);
  } push(temp,x);
  }
   printf(" Stack after sorting \n");
   while(!isempty(temp))
 {
     push(s,pop(temp));
 }
   display(s);
}

void merge (stack *s1,stack *s2) //merging so that the min appears at the top of the stack
{ stack *s3=initialize();
  while(!isempty(s1))
  { push(s3,pop(s1));
  }
  while(!isempty(s2))
  { push(s3,pop(s2));
  }
  sort(s3);
  printf (" Ordered stack after merging \n");
  display (s3);

}

int main()
{ stack *string=initialize();
  stack *s= initialize(); stack *s2=initialize();

  push(s,1);
  push(s,3);
  push(s,2);
  push(s,6);

  push(s2,5);
  push(s2,10);
  push(s2,3);
  push(s2,17);

  int x;
  printf(" 1-Reverse a string \n 2-Check if the given stack is sorted\n 3-Delete the non-prime numbers in a stack \n 4-Sort the elements of the stack  \n 5-Merge two given stacks\n");
  scanf("%d",&x);
  switch(x)
    {
    case 1 :
    {
        reverse_string(string);
        break;
    }
    case 2 :
    {  check_sort(s);
        break;

    }
    case 3 :
    {  delete_nonprime(s);
        break;

    }
    case 4 :
    {
       sort(s);
        break;
    }
    case 5 :
     {  merge(s,s2);
        break;
     }



    return 0;}
 }
