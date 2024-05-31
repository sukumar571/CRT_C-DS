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
void insert_at_back(int value)
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
            Nodeptr temp = curr->next;
            prev->next=temp;
            int item =curr->data;
            free(curr);
            return item;
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
    insert_at_back(10);
    insert_at_back(20);
    insert_at_back(30);
    delete_at_specific(20);
    display();
}