#include<stdio.h>
struct employee
{
    char a[20];
    int id;
    float salary;
};
int main()
{
    struct employee e1;
    scanf("%s",e1.a);
    scanf("%d",&e1.id);
    scanf("%f",&e1.salary);
    printf("%s",e1.a);
    printf("%d",e1.id);
    printf("%f",e1.salary);
    printf("%ld",sizeof(e1));
}