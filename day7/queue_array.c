#include <stdio.h>
#include <stdlib.h>
#define max_size 5
int a[max_size];
int front=-1;
int rear=-1;
void enqueue(int value)
{
    if(rear>=max_size-1)
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
        ++rear;
        a[rear]=value;
    }
}
int dequeue()
{
    if ((front==-1 && rear==-1) || (front==max_size-1 && rear==max_size-1))
    {
        printf("underflow\n");
    }
    else
    {
        printf("%d\n",a[front]);
        front++;
    }
    
}
void display()
{
    if ((front==-1 && rear==-1) || (front==max_size-1 && rear==max_size-1))
    {
        printf("list is empty");
    }
    else
    {
        while (front!=max_size)
        {
            printf("%d ",a[front]);
            front++;
        }
        
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