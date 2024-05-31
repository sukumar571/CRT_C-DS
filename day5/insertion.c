#include<stdio.h>
int main()
{
    int a[5],m;
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 1; i < len; i++)
    {
        m=a[i];
        int j=i-1;
        while (j>=0 && a[j]>m)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=m;
        
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;  
}