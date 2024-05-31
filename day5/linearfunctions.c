#include<stdio.h>
int linearsearch();
int main()
{
    int a[5],count=0;
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len;i++)
    {
        scanf("%d",&a[i]);
    }
    int search;
    scanf("%d",&search);
    int result=linearsearch(a,len,count,search);
    if(result==-1)
    {
        printf("not found");
    }
    else
    {
        printf("found");
    }
    
}
int linearsearch(int a[5],int len,int count,int search)
{
    int mid;
    for(int i=0;i<len;i++)
    {
        if(search==a[i])
        {
            return mid;
            count ++;
        }
    }
    if(count==0)
    {
        return -1;
    }
}