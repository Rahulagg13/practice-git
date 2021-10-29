#include<stdio.h>
#include<stdlib.h>
#define stacksize 100
#define true 1
#define false 0


struct stack{
    int  item[stacksize];
    int top;

}operand_stack;


void initializestack(void)
{
    operand_stack.top=-1;
}

int IsEmpty(void)
{
    if(operand_stack.top==-1)
    {return true;}
    else
    return false;

}
 void push(int  x)
{
    if(operand_stack.top == stacksize-1)
    {
        printf("stack overflow");
        exit(1);
    }
    operand_stack.top=operand_stack.top+1;
    operand_stack.item[operand_stack.top] =x;

}

int  stacktop(void)
{
    int  x;
    x=operand_stack.item[operand_stack.top];
    return x;
}

int  pop(void)
{
    int  x;
    if(IsEmpty())
    {
        printf("stack underflow");
        exit(1);
    }

    x=operand_stack.item[operand_stack.top] ;
   operand_stack.top=operand_stack.top-1;
   return x;

}
int eval(int  a,int  b, char symbol)
{
    switch(symbol)
    {
        case '+': return(a+b);
         break;
        case '-': return(a-b);
        break;
        case '*': return(a*b);
        break;
        case '/': return(a/b);
        break;
        case '%': return(a%b);
        break;
        // case '^': return(a^b);
        // break;
    }
}

int main()
{
    char prefix[20] ,postfix[20];
    int  symbol;
    int a,b;
    int i=0,j;
    int  x,temp,len=0;

    initializestack();
    scanf("%s",prefix);

  for(i=0;prefix<='\0';i++)
  {
    len++;
  }
  j=len-1;
 
   while (i < j) {
      temp = prefix[i];
      prefix[i] = postfix[j];
      postfix[j] = temp;
      i++;
      j--;
   }
   postfix[j]='\0';
   printf("%s",postfix);
 

    

    while(postfix[j]!='\0')
    {
        symbol=postfix[j]-'0';

        if(symbol>=0  && symbol<=9)
        {
            push(symbol);
        }
        else{
            a=pop();
            b=pop();
            x=eval(a,b,postfix[j]);
            push(x);
        }
        j++;
    }
    x=pop();
    printf("%d" ,x);
}



