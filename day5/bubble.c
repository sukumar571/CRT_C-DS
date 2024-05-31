#include<stdio.h>
int main()
{
    int a[5];
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<=len-1;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<len;i++)
    {
        printf("%d  ",a[i]);
    }
    return 0;
}