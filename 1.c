#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define stacksize 100
#define true 1
#define false 0

struct Stack
{
    int item[stacksize];
    int top;

} ;



void initializestack(struct stack *S )
{
    S->top = -1;
}

int stacktop(struct stack *S)
{
    int x;
    x = S->item[S->top];
    return x;
}
int Isempty(struct stack *S)
{
    if (S->top == -1)
    {

        return true;
    }
    else
    {

        return false;
    }
}
void push(struct stack *S,int x)
{
    if (S->top == stacksize - 1)
    {

        printf("stack overflow");
        exit(1);
    }
    S->top = S->top + 1;
    S->item[S->top] = x;
}
int pop(struct stack *S)
{
    int x;
    if (Isempty(struct stack *S))
    {
        printf("stack underflow");
        exit(1);
    }

    x = S->item[S->top];
    S->top = S->top - 1;
    return x;
}
// int prec(char a, char b)
// {

//     if(a=='('||b=='(')
//     {
//         return false;
//     }
//     else
//         {
//             if(b==')')
//             {
//                 return true;

//             }
//         }



//     if (a == '^' || a == '*' || a == '/' || a == '%')
//     {

//         if (b == '^')
//             return false;
//         else
//             return true;
//     }
//     else
//     {
//         if (a == '+' || a == '-')
//         {
//             if (b == '+' || b == '-')
//                 return true;
//             else
//                 return false;
//         }
//     }

// }

int main()
{
    int digits[10];
    int x;
    struct stack S1,S2;
    initializestack(&S1);
    initializestack(&S2);
    push(&S1,100);
    x=pop(&S1);
    printf("%d",x);
    
}
