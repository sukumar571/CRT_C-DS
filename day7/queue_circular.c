#include <stdio.h>
#include <stdlib.h>
#define max_size 5
int a[max_size];
int front=-1;
int rear=-1;
void enqueue(int value)
{
    if((rear+1)%max_size==front)
    {
        printf("overflow\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        a[rear]=value;
    }
    else
    {
        rear=(rear+1)%max_size;
        a[rear]=value;
    }
}
int dequeue()
{
    if ((front==-1 && rear==-1))
    {
        printf("underflow\n");
    }
    else
    {
        printf("dequeue elements:%d\n",a[front]);
        front=(front+1)%max_size;
    }
    
}
void display()
{
    int i=front;
    if ((front==-1 && rear==-1))
    {
        printf("list is empty");
    }
    else
    {
        while (i!=rear)
        {
            printf("the element in the queue:%d\n",a[i]);
            i=(i+1)%max_size;
        }
        printf("the element in the queue:%d\n",a[rear]);
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    enqueue(40);
    enqueue(50);
    dequeue();
    enqueue(60);
    display();
}