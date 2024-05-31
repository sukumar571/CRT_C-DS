#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
//by using typedef 
typedef struct node *Nodeptr;
Nodeptr head=NULL;
int is_empty()
{
    return head==NULL;
}
void insert_at_front(int value)
{
    // creating a newnode
    Nodeptr newnode=malloc(sizeof(Nodeptr));
    newnode->data=value;
    newnode->next=NULL;
    // if list is empty
    if (is_empty())
    {
        head=newnode;
    }
    //if list is not empty
    else
    {
        Nodeptr curr=head;
        while (curr->next != NULL)
        {
            curr=curr->next;
        }
        curr->next=newnode;
        
    }   
}
void insert_at_specific(int key,int value)
{
    Nodeptr newnode=malloc(sizeof(Nodeptr));
    newnode->data=value;
    newnode->next=NULL;
    if (is_empty())
    {
        printf("can not insert:");
    }
    else
    {
        Nodeptr curr =head;
        while (curr != NULL && curr->data != key)
        {
            curr=curr->next;
        }
        if (curr==NULL)
        {
            printf("key not found");
        }
        else if (curr->next=NULL)
        {
            curr->next=newnode;
        }
        else
        {
            Nodeptr temp = curr->next;
            curr->next=newnode;
            newnode->next=temp;
        }
    }
    
}
// displaying the elements in list
void display()
{
    Nodeptr curr=head;
    while (curr != NULL)
    {
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}
int main()
{
    insert_at_front(10);
    insert_at_front(20);
    insert_at_front(30);
    insert_at_specific(20,40);
    display();
}