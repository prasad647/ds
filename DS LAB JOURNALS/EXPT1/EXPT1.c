#include<stdio.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push();
void pop();
void display();
int main()
{
    int ch;
    do{
        printf("\n***Stack Operations***");
        printf("\n\n1. Push\t2. Pop\t3. Display\t4.Exit");
        printf("\nEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: printf("\nBreak point");
                    break;
            default: printf("\nWrong Choice!! Please enter the right choice 1\2\3\4");
                     break;
        }
    }while(ch!=4);
}
void push()
{
    int val;
    if(top==MAX-1)
        printf("\nStack is Full !! Overflow!!");
    else
    {
        printf("\nEnter the element to be pushed:");
        scanf("%d",&val);
        top++;
        stack[top]=val;
    }
}
void pop()
{
    if(top==-1)
        printf("\nStack is empty!! Underflow!!");
    else
    {
        printf("\nThe popped element is %d\n",stack[top]);
        top--;
    }
}
void display()
{
    int i;
    if(top==-1)
        printf("\nStack is Empty!! Underflow!!");
    else
    {
        printf("\nThe Stack Status:");
        for(i=top;i>=0;i--)
            printf("\n %d",stack[i]);
    }
}

