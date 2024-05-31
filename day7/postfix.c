/*s-1: operand push into result
s-2: if ( push into stack 
s-3: if ) check if stack is empty and until( pop all the operators from stack and push into the stack
s-4:  if operator check with the priorities and push accordingly into either stack or result*/
#include<stdio.h>
#include<string.h>
#define max_size 100
//function for operators
int operator1(char symbol)
{
    if(symbol =='^')
        return 3;
    else if(symbol =='*'|| symbol=='/')
        return 2;
    else if(symbol =='+'|| symbol=='-')
        return 1;
    else
        return -1;
}
//function to convert your infix expression to postfix expression
int infixtopostfix(char input[])
{
    int len=strlen(input);
    char result[50],stack[50];
    int j=0;//result index
    int sindex=-1;//stack index
    for(int i=0;i<len;i++)
    {
        char symbol=input[i];
        if((symbol >='a' && symbol <='z')||(symbol >='A' && symbol <='Z'))
        {
            result[j++]=symbol;
        }
        else if(symbol =='(')
        {
            stack[++sindex]=symbol;//stack
        }
        else if(symbol ==')')
        {
           while(sindex>=0 && stack[sindex]!='(')//'('!='('
           {
               result[j++]=stack[sindex--];
           }
           sindex--;//poping the '('
        }
        else
        {
            while(sindex>=0 && operator1(symbol) <= operator1(stack[sindex]))
            {
                result[j++]=stack[sindex--];
            }
            stack[++sindex]=symbol;
        } 
    }
    while(stack[sindex]!=-1)
    {
        result[j++]=stack[sindex--];
    }
    result[j]='\0';
    printf("%s",result);
}
int main()
{
    char input[max_size];
    scanf("%s",input);
    infixtopostfix(input);
    return 0;
}