#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
char stack[MAX];
int top=-1,j=0;
void push(char item);
char pop(void);
bool isOperator(char token);
int precedance(char token);
void infixtopostfix(char[],char[]);
int main()
{
    char infix[MAX],postfix[MAX];
    int i;
    printf("\nEnter the infix expression:");
    gets(infix);
    push('(');
    infixtopostfix(infix,postfix);
    puts(postfix);
    return 0;
}
void push(char item)
{
    if(top>=MAX-1)
        printf("\nStack is full!! Overflow");
    else
    {
        top++;
        stack[top]=item;
    }
}
char pop(void)
{
    char item;
    if(top<0)
    {
        printf("\nStack is Empty!! Underflow");
        exit(1);
    }
    else
    {
        item=stack[top];
        top--;
        return(item);
    }
}
bool isOperator(char token)
{
    if(token=='+'||token=='-'||token=='*'||token=='/'||token=='^')
        return true;
    return false;
}
int precedance(char token)
{
    if(token=='^')
        return 3;
    else if(token=='*'||token=='/')
        return 2;
    else if(token=='+'||token=='-')
        return 1;
    else
        return 0;
}
void infixtopostfix(char infix[],char postfix[])
{
    int i=0;
    char token, stacktop;
    strcat(infix,")");
    while(infix[i]!='\0')
    {
        token=infix[i];
        if(isdigit(token)||isalpha(token))
        {
            postfix[j]=token;
            j++;
        }
        else if(isOperator(token))
        {
            stacktop=pop();
            while((isOperator(stacktop))&&(precedance(stacktop)>=precedance(token)))
            {
                postfix[j]=stacktop;
                stacktop=pop();
                j++;
            }
            push(stacktop);
            push(token);
        }
        else if(token=='(')
            push(token);
        else if(token==')')
        {
            stacktop=pop();
            while(stacktop!='(')
            {
                postfix[j]=stacktop;
                stacktop=pop();
                j++;
            }
        }
        i++;
    }
    postfix[j]='\0';
}
