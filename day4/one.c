#include<stdio.h>
int factorial(int a)
{
       if (a==0 || a==1)
       {
            return 1;
       }
       else
       {
            return a*factorial(a-1);
       }
       
}
int main()
{
    int a;
    scanf("%d",&a);
    printf("%d",factorial(a));
    return 0;
}