#include<stdio.h>
int main()
{
    int a[6],count=0;
    int len=sizeof(a)/sizeof(a[0]);
    printf("enter the array elements:");
    for(int i=0;i<len;i++)
    {
        scanf("%d",&a[i]);
    }
    int search;
    scanf("%d",&search);
    for(int i=0;i<len;i++)
    {
        if(search==a[i])
        {
            printf("search element was found");
            count++;
        }
    }
    if(count==0)
    {
        printf("search element was not found");
    }
    return 0;
}