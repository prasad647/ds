#include<iostream>
using namespace std;
class Node
{ public:
    int data;
    Node* next;
};
class LinkedList:public Node
{
    Node *head,*tail;
    public:
    LinkedList()
    {
        head=NULL;
        tail=NULL;
    }
    void createNode();
    void insert();
    void delet();
    void display();
    void search();
};
 int main()
 {
     LinkedList lst;
     int ch;
     while(1)
        {
            cout<<"\n**** MENU ****";
            cout<<"\n1:CREATE\t2: INSERT\t3:DELETE\t4:SEARCH\t5: DISPLAY\t6:EXIT\n";
            cout<<"\nEnter Your Choice:";
            cin>>ch;
            switch(ch)
                  {
                    case 1:lst.createNode();
                           break;
                    case 2:lst.insert();
                           break;
                    case 3:lst.delet();
                           break;
                    case 4:lst.search();
                           break;
                    case 5:lst.display();
                           break;
                    case 6:return 0;
                    }
        }    return 0;
}
void LinkedList::createNode()
{
    Node *temp=new Node;
    int n;
    cout<<"\n Enter an Element:";
    cin>>n;
    temp->data=n;
    temp->next=NULL;
    if(head==NULL)
        {
            head=temp;
            tail=head;
        }
    else
        {
            tail->next=temp;
            tail=temp;
        }
}
void LinkedList :: insert()
 {
     int n;
     Node *temp=new Node;
     cout<<"\nEnter an Element:";
     cin>>n;
     temp->data=n;
     temp->next=NULL;
     temp->next=head;
     head=temp;
}
void LinkedList::delet()
{
    Node *prev=NULL,*cur=head;
    int count=1,pos,ch;

    if(cur!=NULL)
        {
            cout<<"\nEnter the Position of Deletion:";
            cin>>pos;
            while(count!=pos)
                {
                    prev=cur;
                    cur=cur->next;
                    count++;
                }
             if(count==pos)
                {
                    cout<<"\nDeleted Element is: " <<cur->data;
                    prev->next=cur-> next;
                }
        }
    else
        cout<<"\nNot Able to Delete";
}
void LinkedList::display()
{
     Node *temp=head;
      if(temp==NULL)
        {
            cout<<"\nList is Empty";
        }
        while(temp!=NULL)
            {
                cout<<temp->data;
                cout<<"-->";
                temp=temp->next;
            }
        cout<<"NULL";
}
void LinkedList::search()
{
    int value,pos=0;
    bool flag=false;
    if(head==NULL)
    {
        cout<<"\nList Empty";
        return;
    }
    cout<<"\nEnter the number to be searched:";
    cin>>value;
    Node *temp;
    temp=head;
    while(temp!=NULL)
    {
        pos++;
        if(temp->data==value)
        {
            flag=true;
            cout<<"Element"<<value<<"found at position"<<pos;
            return;
        }
        temp=temp->next;
    }
    if(!flag)
        cout<<"\nElement not found";
}
