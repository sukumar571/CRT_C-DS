#include <stdio.h>
#define max_size 50
int operator1(char symbol)
{
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol== '/' || symbol == '^')
    {
        return 1;
    }
    return 0;
    
}
int postfix_evaluation(char input[])
{
    int stack[max_size];
    int j=-1;
    int i=0,result;
    int symbol = input[i];
    while (symbol != '\0')
    {
        if (symbol >= '0' && symbol <= '9')
        {
            int num=symbol-'0';
            stack[++j]=num;
        }
        else if (operator1(symbol))
        {
            int op2=stack[j--];
            int op1=stack[j--];
            switch (symbol)
            {
            case'+': result=op2+op1;break;
            case'-': result=op2-op1;break;
            case'*': result=op2*op1;break;
            case'/': result=op2/op1;break;
            case'^': result=op2^op1;break;
            }
            stack[++j]=result;
        }
        i++;
        symbol=input[i];
        
    }
    result=stack[j--];
    return result;   
}
int main()
{
    char input[max_size];
    scanf("%s",input);
    int r=postfix_evaluation(input);
    printf("%d",r);
    return 0;
}