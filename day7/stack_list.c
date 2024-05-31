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
//declare a head and tail
Nodeptr head=NULL;
Nodeptr tail=NULL;
//if list is empty by using function
int is_empty()
{
    return head==NULL;
}
//create a function for insert at front
void push(int value)
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
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
//delete at front
int pop()
{
    if(is_empty())
    {
        printf("list is empty we can't delete an element");
    }
    else
    {
        Nodeptr temp=head->next;
        int item=tail->data;
        temp=tail->prev;
        tail->prev=NULL;
        free(tail);
        temp->next=NULL;
        tail=temp;
        return item;
    }
}
int peek()
{
    return tail->data;
}
//displaying the elements in list
void display()
{
    Nodeptr curr=head;
    while(curr!=NULL)
    {
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    printf("%d\n",pop());
    printf("%d\n",peek());
    display();
}