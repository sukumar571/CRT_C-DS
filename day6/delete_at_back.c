//write a program on deleting the elements at back using single linked list
#include<stdio.h>
#include<stdlib.h>
//create a node using structure
struct node
{
    int data;
    struct node *next;
};
//by using typedef i am creating a alias name to struct
typedef struct node *Nodeptr;
//declare a head
Nodeptr head=NULL;
//if list is empty by using function
int is_empty()
{
    return head==NULL;
}
//create a function for insert at front
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
    }
    //if list is not empty
    else
    {
        Nodeptr curr=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=newnode;
    }
}
//delete at back
int delete_at_back()
{
    if(is_empty())
    {
        printf("list is empty we can't delete an element");
    }
    else
    {
        Nodeptr prev=NULL;
        Nodeptr curr=head;
        while(curr->next!=NULL)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        int item=curr->data;
        free(curr);
        return item;
    }
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
    insert_at_back(10);
    insert_at_back(20);
    insert_at_back(30);
    printf("%d\n",delete_at_back());
    display();
}