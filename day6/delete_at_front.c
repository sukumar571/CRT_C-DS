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
int delete_at_front()
{
    if (is_empty())
    {
        printf("list is empty we can't delete");
    }
    else
    {
        Nodeptr temp = head->next;
        int item=head->data;
        head->next=NULL;
        free(head);
        head=temp;
        return item;
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
    printf("%d\n",delete_at_front());
    display();
}