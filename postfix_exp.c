
/**********************EVALUATION OF POSTFIX EXPRESSION USING STACK**********************/
/********************************AUTHOR:BHAVYA JINDAL***********************************/
/***************************************************************************************/
#include<stdio.h>
#include<math.h>
struct Stack
{
    int item[10];
    int Top;
};
/***************************************************************************************/
struct  Stack S;
/***************************************************************************************/
void initialise(void)
{
  S.Top=-1;
}
/***************************************************************************************/
void push(char x)
{
    if(S.Top==-1)
    {
        printf("\n \n Stack Overflowes");
        return 0;
    }

    S.Top++;
    S.item[S.Top]=x;

}
/***************************************************************************************/
int pop( )
{
    int x;
    x=S.item[S.Top];
    S.Top--;
    return x;
}
/***************************************************************************************/
int StackTop(void)
{
    int m;
    m=S.item[S.Top];
    return m;
}
/***************************************************************************************/


int Evaluate(int a,int b, char op)
{
    switch(op)
    {
        case '+': return a+b; break;
        case '-': return a-b; break;
        case '*': return a*b; break;
        case '/': return a/b; break;
        case '%': return a%b; break;
        case '^': return pow(a,b); break;
    }
}
/***************************************************************************************/
void post(char p[])
{
    int ans,a,b,i=0;
    char x;
    while(p[i]!='\0')
    {
        x=p[i];
        if (x>='0' && x<='9')
        {
            push(x-'0');
        }
        else{
            b=pop();
            a=pop();
            ans=Evaluate(a,b,x);
            push(ans);
        }
        i++;
    }
    printf("\nEvaluated value is  : %d",StackTop());
    printf("\n\n");
}

/***************************************************************************************/
int main()
{
    char postfix1[20]="345*7+-";
    char postfix2[20]="32^6*822^/-";
    char postfix3[20]="663/*";
    printf("Postfix Expression is : %s",postfix1);
    post(postfix1);
    printf("Postfix Expression is : %s",postfix2);
    post(postfix2);
    printf("Postfix Expression is : %s",postfix3);
    post(postfix3);

}
/***************************************************************************************/
/***************************************************************************************
OUTPUT:

Postfix Expression is : 345*7+-
Evaluated value is  : -24

Postfix Expression is : 32^6*822^/-
Evaluated value is  : 52

Postfix Expression is : 663/*
Evaluated value is  : 12

/***************************************************************************************/
