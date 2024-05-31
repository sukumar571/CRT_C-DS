//write a program on inserting the elements at front using circular linked list
#include<stdio.h>
#include<stdlib.h>
//create a node using structure
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
//by using typedef i am creating a alias name to struct
typedef struct node *Nodeptr;
//declare a head and tail
Nodeptr head=NULL;
Nodeptr tail=NULL;
//if list is empty by using function
int is_empty()
{
    return head==NULL;
}
void insert_at_back(int value)
{
    //create a newnode
    Nodeptr newnode=malloc(sizeof(Nodeptr));
    newnode->data=value;
    newnode->next=NULL;
    //if list is empty
    if(is_empty())
    {
        head=newnode;
        tail=newnode;
    }
    //if list is not empty
    else
    {
        newnode->prev=tail;
        newnode->next=head;
        head->prev=newnode;
        tail->next=newnode;
        tail=newnode;
    }
}
//create a function for insert at front
void insert_at_specific(int key,int value)
{
    //create a newnode
    Nodeptr newnode=malloc(sizeof(Nodeptr));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    //if list is empty
    if(is_empty())
    {
        head=newnode;
        tail=newnode;
    }
    //if list is not empty
    else
    {
        Nodeptr curr=head;
        while(curr->next!=head  && curr->data!=key)
        {
            curr=curr->next;
        }
        if(curr->next==head)
        {
            printf("key not found");
        }
        else if(curr==head && curr->data==key)
        {
            curr->next=newnode;
            newnode->prev=curr;
            curr->prev=newnode;
            newnode->next=curr;
        }
        else
        {
            Nodeptr temp=curr->next;
            curr->next=newnode;
            newnode->prev=curr;
            newnode->next=temp;
            temp->prev=newnode;
        }
    }
}
//displaying the elements in list
void display()
{
    Nodeptr curr=head;
    do
    {
        printf("%d ",curr->data);
        curr=curr->next;
    }
    while (curr!=head);
    printf("\n");
}
int main()
{
    insert_at_back(10);
    insert_at_back(20);
    insert_at_back(30);
    insert_at_specific(20,40);
    display();
}