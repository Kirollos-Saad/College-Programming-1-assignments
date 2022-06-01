#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct {
 int items[SIZE];
 int top;
  } stack ;

stack *init ()
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

int is_full (stack *s)
{ if( s->top== SIZE ) return 1;
  else
    return 0;
}

int is_empty (stack *s)
{
    if(s->top==0) return 1;
  else
    return 0;
}
int peek(stack *s)
{
  return s->items[s->top - 1];
}
void display_stack (stack *s)
{ stack *temp=init();
  while(!isempty(s) )
 {
   int x=pop(s);
   printf("%d \n",x);
   push(temp,x);
 }
 while(!is_empty(temp))
 {
     push(s,pop(temp));
 }

}

typedef struct
{ int *items; int front; int rear; int capacity; int numberofitems;
} Queue ;

Queue* initialize (int n)
{ Queue *q=malloc(sizeof (Queue));
  q->rear=0; q->front=0; q->numberofitems=0; q->capacity=n; q->items= malloc(n*sizeof(int));
    return q;
}

void enqueue (Queue *q, int x)
{ q->items[q->rear]=x;
    q->rear=(q->rear +1)%q->capacity;
      q->numberofitems ++;
}

int dequeue (Queue *q)
{ int x= q->items[q->front];
    q->front=(q->front +1)%q->capacity;
      q->numberofitems --;
      return x;
}
int isempty (Queue *q)
{ if(q->numberofitems==0) return 1;
   else
    return 0;
}
int isfull (Queue *q)
{ if(q->numberofitems==q->capacity) return 1;
   else
    return 0;
}
int size (Queue *q)
{ return q->numberofitems;}

int getfront (Queue *q)
{ return q->items[q->front];
}
int getrear (Queue *q)
{ if(q->rear==0) return q->items[q->capacity-1];
  else
    return q->items[q->rear-1];
}
void display (Queue *q)
{ int c= size(q);
  Queue *temp= initialize(c);
  while (!isempty(q))
    {
      int x=dequeue(q); printf("%d \n",x); enqueue(temp,x);
    }
   while (!isempty(temp))
   { enqueue(q,dequeue(temp));
   }
}
void getmax(Queue *q)
{   int c= size(q);
    Queue *temp=initialize(c);
    int max=dequeue(q); enqueue(temp,max);
    while(!isempty(q))
    { int x=dequeue(q);
      if (x>max) max=x;
        enqueue(temp,x);
    }
    while(!isempty(temp))
        enqueue(q,dequeue(temp));
    printf("The maximum element in the queue is : %d",max);
}
void swap(Queue *q)
{   int c=size(q); Queue *s=initialize(c); int x=getfront(q); int y=getrear(q); int j=1;
  while(!isempty(q))
  {
     enqueue(s,dequeue(q));
  } dequeue(s); enqueue(q,y);
  while(!isempty(s))
  { if(j++==c-1)
   { enqueue(q,x); break;
   }
   else
   { enqueue(q,dequeue(s));
   }

  }
  printf("Your queue after swapping \n");
  display(q);

}
void insert_newvalue(Queue *q)
{ Queue *temp= initialize(20); int x,index; int i=0; int c=size(q);
  printf("Enter the new value \n"); scanf("%d",&x); printf("Enter its index \n");scanf("%d",&index);
  while (!isempty(q))
    { enqueue(temp,dequeue(q));
    }
    if(index==c)
    {
        while (!isempty(temp))
        { enqueue(q,dequeue(temp));
        } enqueue(q,x);
    }
    else if (index>c)
    { printf("Invaid index, please insert index between 0 and %d \n",c); return ;
    }
    else{
    while (!isempty(temp))
    { if(i==index)
      { enqueue(q,x);enqueue(q,dequeue(temp)); i++;

      } else {enqueue(q,dequeue(temp)); i++;}

    }   }
    printf("Your queue after inserting new number\n"); display(q);


}
Queue* reverseOdd(Queue *q)
{   int c=size(q);
    Queue *copy =initialize(c); stack *temp=init();
    while(!isempty(q))
    { int x=dequeue(q);
        if(x%2)
        {
            push(temp,x);enqueue(copy,1);
        } else enqueue(copy,x);
    }
    while (!isempty(copy))
    {  if(getfront(copy)==1)
        {enqueue(q,pop(temp));dequeue(copy);

        }
        else enqueue(q,dequeue(copy));

    }
    printf("Your Queue after reversing odds\n");
    display(q);
}
Queue* reverse(Queue *q, int k)
{
    int i=0; Queue *copy=initialize(20); stack *s=init();
    for(i=0;i<k;i++)
    {
        push(s,dequeue(q));
    }
    while (!isempty(q)) enqueue(copy,dequeue(q));
    while(!is_empty(s))
    { int y=pop(s);enqueue(q,y);
    }
    while (!isempty(copy)) enqueue(q,dequeue(copy));
    return q;
}

int main()
{  Queue *q=initialize(20);
   /*enqueue(q,4);
   enqueue(q,8);
   enqueue(q,7);
   enqueue(q,10); */
   enqueue(q,14);
   enqueue(q,13);
   enqueue(q,17);
   enqueue(q,8);
   enqueue(q,4);
   enqueue(q,10);
   enqueue(q,11);
   enqueue(q,4);
   enqueue(q,15);
   enqueue(q,18);
   enqueue(q,19);
    int x;
  printf(" 1-Get max element\n 2-Swap between head and tail\n 3-Insert new value in specific index \n 4-ReverseOdd  \n 5-Reverse the firts kth elements in a file \n");
  scanf("%d",&x);
  switch(x)
    {
    case 1 :
    {
        getmax(q);
        break;
    }
    case 2 :
    {  swap(q);
        break;

    }
    case 3 :
    {  insert_newvalue(q);
        break;

    }
    case 4 :
    {
       reverseOdd(q);
        break;
    }
    case 5 :
     {  Queue *s=initialize(20);
        FILE *f= fopen("filename.txt","r"); int z;
 if(f==NULL)
  {  printf(" file doesn't exist \n");

  }
  while(!feof(f)){
        fscanf(f,"%d",&z);
        enqueue(s,z);
                 } fclose(f);
    Queue* temp=reverse(s,4);
    f=fopen("filename.txt","w");
    while(!isempty(temp))
    {
        fprintf(f,"%d ",dequeue(temp));
    } fclose(f);
        break;
      }
 }
    return 0;
}
