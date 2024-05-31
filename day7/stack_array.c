#include<stdio.h>
#include<stdlib.h>
#define max_size 5
int stack[max_size];
int top=-1;
void push(int value)
{
    if(top>=max_size-1)
    {
        printf("overflow\n");
    }
    else
    {
        stack[top+1]=value;
        top=top+1;
    }
}
int pop()
{
    if ((top==-1))
    {
        printf("underflow\n");
    }
    else
    {
        printf("%d\n",stack[top]);
        top=top-1;
    }
    
}
int peek()
{
   printf("%d\n",stack[top]);
}
void display()
{
    for (int i = 0; i <= top; i++)
    {
           printf("%d ",stack[i]);
    }
    
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    pop();
    peek();
    display();
}
