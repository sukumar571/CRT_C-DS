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
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
//delete at front
int delete_at_specific(int key)
{
    if (is_empty())
    {
        printf("can't delete if list id empty");
    }
    else
    {
        Nodeptr prev = NULL;
        Nodeptr curr = head;
        while (curr != NULL && curr->data!=key)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr==NULL)
        {
            printf("key not found");
        }
        else if (curr->next==NULL)
        {
            free(curr);
        }
        else
        {
            Nodeptr temp1=curr->next;
            Nodeptr temp=curr->prev;
            curr->prev=NULL;
            curr->next=NULL;
            int item=curr->data;
            free(curr);
            temp->next=temp1;
            temp1->prev=temp;
            return item;
        }
        
        
        
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
    printf("%d\n",delete_at_specific(20));
    display();
}