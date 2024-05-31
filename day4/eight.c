#include <stdio.h>
int main()
{  
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<=a-i-1;j++)
        {
            printf("*");
        }
        for(int k=1;k<=i;k++)
        {
            printf(" ");
        }
        for(int m=1;m<=i;m++)
        {
            printf(" ");
        }
        for(int l=1;l<=a-i;l++)
        {
            printf("*");   
        }
        printf("\n");
    }
    for(int i=1;i<a;i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("*");
        }
        for(int p=1;p<=a-i-1;p++)
        {
            printf(" ");
        }
        for(int r=1;r<=a-i-1;r++)
        {
            printf(" ");
        }
        for(int q=0;q<=i;q++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}