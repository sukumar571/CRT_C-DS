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
int delete_at_specific(int key)
{
    if (is_empty())
    {
        printf("can't delete if list id empty");
    }
    else
    {
        Nodeptr curr = head;
        while (curr->next != head && curr->data!=key)
        {
            curr = curr->next;
        }
        if (curr->next == head)
        {
            printf("key not found");
        }
        else if (curr->next==head && curr->data!=key)
        {
            free(curr);
        }
        else
        {
            Nodeptr temp1=curr->prev;
            Nodeptr temp=curr->next;
            curr->prev=NULL;
            curr->next=NULL;
            temp->prev=temp1;
            temp1->next=temp;
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
    delete_at_specific(20);
    display();
}