#include<stdio.h>
#include <stdlib.h>
int main()
{
    int a[10],n,*ptr;
    scanf("%d",&n);
    ptr=(int*)calloc(n,sizeof(int));
    printf("%u",ptr);
    for(int i=0;i<n;i++)
    {
        scanf("%d",(ptr+1));
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d",ptr+1);
    }
    return 0;
}