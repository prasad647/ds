#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void insert();
void delete();
void display();
int queue_arr[MAX];
int rear=-1;
int front=-1;
int main()
{
    int choice;
    while(1)
    {
        printf("1. Insert an element\t2. Delete an element\t3. Display the queue\t4. Quit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(1);
            default: printf("\nWrong Choice!!");
                    break;
        }
    }
    return 0;
}
void insert()
{
    int add_item;
    if(rear==MAX-1)
        printf("\nQueue Overflow!! Insertion not possible !!\n");
    else
    {
        if(front==-1)
            front=0;
        printf("\nEnter the element to be inserted in Queue:");
        scanf("%d",&add_item);
        rear++;
        queue_arr[rear]=add_item;
    }
}
void delete()
{
    if(front==-1||front>rear)
    {
        printf("Queue Underflow!! Deletion not possible!! \n");
        return;
    }
    else
    {
        printf("\nElement deleted from Queue is : %d\n",queue_arr[front]);
        front++;
    }
}
void display()
{
    int i;
    if(front==-1)
        printf("\nQueue is Empty!!\n");
    else
    {
        printf("\nQueue is:\n");
        for(i=front;i<=rear;i++)
            printf("%d ",queue_arr[i]);
        printf("\n");
    }
}
