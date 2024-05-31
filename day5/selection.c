#include<stdio.h>
int main()
{
    int a[5],count=0;
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len-1;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<=len-1;i++)
    {
        for(int j=i+1;j<len-1;j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<len-1;i++)
    {
        printf("%d  ",a[i]);
    }
    return 0;
}