#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
typedef struct node
{
    float data; struct node *next;
} node;
typedef struct
{  node *top;
} stack;
node *newnode(float x)
{ node *n=malloc(sizeof(node));
  n->data=x; n->next=NULL;
    return n;
}
stack *initialize()
{ stack *s=malloc(sizeof(stack));
  s->top= NULL;
    return s;
}
void push(stack *s,float value)
{ node *n=newnode(value);
  if(s->top==NULL) s->top=n;
  else
  {n->next=s->top; s->top=n;
  }

}
float pop(stack *s)
{ node *temp=s->top;
  float x= temp->data; s->top= temp->next;
  free(temp);
    return x;
}
int isempty(stack *s)
{ if(s->top==NULL) return 1;
    else
        return 0;
}
float peek(stack *s)
{
    return s->top->data;
}
//////////////////////////////////////////////END OF STACK////////////////////////////////////////////////////////
int is_op(char ch)
{
    return ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch=='^'));
}
void Handle_Errors (int x)
{
    if (x==1||x==3) printf ("INVALID EXPRESSION: insufficient number of operands\n ");
    if (x==2)       printf ("INVALID EXPRESSION: unsupported characters entered\n ");
    if (x==4)       printf ("INVALID EXPRESSION: Division by zero\n ");
    if (x==5)       printf ("INVALID EXPRESSION: invalid number of brackets\n ");
    exit (-1);
}
void Check_Errors (char * infix)
{
    int i,count_Brac=0;
    if (is_op(infix[0])&&infix[0]!='-') Handle_Errors(1);
    for (i=0;infix[i];i++)
    {
        if (!is_op(infix[i]) && !isdigit(infix[i]) && infix[i]!='.' && infix[i]!='(' && infix[i]!=')')    Handle_Errors(2);
        if (is_op(infix[i])&& is_op(infix[i+1])&&infix[i+1]!='-') Handle_Errors(3);
        if (infix[i]=='/' && infix[i+1]=='0')   Handle_Errors(4);
        if(infix[i]=='(')   count_Brac ++;
        if(infix[i]==')')   count_Brac --;
    }
    if (count_Brac) Handle_Errors(5);
}

int priority (char op)
{
	if (op =='+' || op== '-')   return 1;
	if (op =='*' || op== '/')   return 2;
	if (op =='^')               return 3;
	else return 0;
}
int isNeg(char * infix ,int i)
{

    if (i==0) return 1;
    if ((!isdigit(infix[i-1]))&&(infix[i-1]!=')'))  return 1;
    return 0;
}
void Remove_Space(char*infix)
{
    int i,j;
    for (i=0;infix[i];i++)
        if (infix[i]==' ')
        {
            for (j=i;infix[j];j++)
                infix[j]=infix[j+1];
            i--;
        }
}
char*  infixToPostfix(char* infix)
{
    Remove_Space(infix);
    Check_Errors(infix);
    stack *s= initialize();
    char *postfix = malloc(2*strlen(infix));
    int i,j=0;
    for(i=0;infix[i];i++)
    {
    	if (isdigit(infix[i])||infix[i]=='.')
                postfix[j++]=infix[i];
        else if (infix[i]=='-'&& isNeg(infix,i))
                postfix[j++]=infix[i];
    	else if (infix[i]=='(')
                push(s,(float)infix[i]);
    	else if (isempty(s))
    		{
    			postfix[j++]=' ';
    			push(s,(float)infix[i]);
    		}
    	else if(infix[i]==')')
    		{
    			while((char)peek(s)!='(')
    			{
    				postfix[j++]=' ';
    				postfix[j++]=(char)pop(s);
    			}
    			pop(s);
    		}
    	else
    		{
    			while (!isempty(s)&& (char)peek(s)!='(' &&  priority(infix[i])<=priority((char)peek(s)))
    				{
    					postfix[j++]=' ';
    					postfix[j++]=(char)pop(s);
    				}
    			postfix[j++]=' ';
    			push(s,(float)infix[i]);

    		}
    }
    while(!isempty(s))
    	{
    		postfix[j++]=' ';
    		postfix[j++]=(char)pop(s);
    	}
    postfix[j]='\0';
    return postfix;
}
float evaluate(char str,float x1,float x2)
{
    if (str=='+')       return (x1+x2);
    else if (str=='-')  return (x1-x2);
    else if (str=='*')  return (x1*x2);
    else if (str=='/')  return (x1/x2);
    else if (str=='^')  return (pow(x1,x2));
    else return 0;
}
float evaluatepostfix (char *postfix)
{
    stack *s=initialize();
    float x,y,z;
    char *token= strtok(postfix, " ");
    while (token !=NULL)
    {
        if (isdigit(token[0])||((token[0]=='-')&&(isdigit(token[1]))))
        {
            push(s,atof(token));
        }
      else
      {
          x=pop(s);
          y=pop(s);
          z=evaluate(token[0],y,x);
          push(s,z);
      }
      token= strtok(NULL, " ");
    }
    z=pop(s);
    return z;
}
void replaceNewLineBySpace(char *s)
{
    char *s1 = s;
    while((s1 = strstr(s1, "\n")) != NULL)
        *s1 = ' ';
}
int main()
{
    char infixExpr[256] = "";

    printf("Enter an expression you want to evaluate or Ctrl+Z to exit: ");
    while(fgets(infixExpr, 255, stdin) != NULL)
    {
        replaceNewLineBySpace(infixExpr);
        char*postfix=infixToPostfix(infixExpr);
        printf("Postfix : %s\n", postfix);
        float result = evaluatepostfix(postfix);
        printf("Result: %f\n\n", result);
        printf("Enter an expression you want to evaluate or Ctrl+Z to exit: ");
    }
    return 0;
}
