//write a program on deleting the elements at front using double linked list
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
//declare a front and rare
Nodeptr front=NULL;
Nodeptr rear=NULL;
//if list is empty by using function
int is_empty()
{
    return front==NULL;
}
//create a function for enqueue
void enqueue(int value)
{
    //create a newnode
    Nodeptr newnode=malloc(sizeof(Nodeptr));
    newnode->data=value;
    newnode->next=NULL;
    //if list is empty
    if(is_empty())
    {
        front=newnode;
        rear=newnode;
    }
    //if list is not empty
    else
    {
        rear->next=newnode;
        newnode->prev=rear;
        rear=newnode;
    }
}
//create a function dequeue
int dequeue()
{
    if(is_empty())
    {
        printf("list is empty we can't delete an element");
    }
    else
    {
        Nodeptr temp=front->next;
        int item=front->data;
        temp->prev=NULL;
        front->next=NULL;
        front=temp;
        return item;
    }
}
int getfront()
{
    if (is_empty())
    {
        printf("list is empty");
    }
    return front->data;
}
//displaying the elements in list
void display()
{
    Nodeptr curr=front;
    while(curr!=NULL)
    {
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    printf("%d\n",dequeue());
    printf("%d\n",getfront());
    display();
}