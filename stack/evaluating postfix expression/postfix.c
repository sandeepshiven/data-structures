#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define MAX 1000

int stack[MAX];
int top = -1;

enum boolean
{
    false,true
};


int DoOperation(char , int , int );
enum boolean IsOperator(char );
enum boolean IsNumeric(char );


void main()
{
    char string[1000];
    int result;
    printf("Enter the expression with numbers and oprerators seperated by ' ' or ','\n");
    gets(string);
    result = evaluate_postfix(string);
    printf("The result is: %d",result);
}


int evaluate_postfix(char str[])
{
    int i,length,operation,operand = 0;
    char operand1,operand2;
    length = strlen(str);
    for(i=0;i<length;i++)
    {
        if(str[i]==' ' || str[i] == ',')
            continue;

        else if (IsOperator(str[i])==true)
        {
            operand1 = stack[top--];
            operand2 = stack[top--];
            operation = DoOperation(str[i],operand2,operand1);
            stack[++top] = operation;
        }

        else if(IsNumeric(str[i])==true)
        {
            operand = 0;
            while(i<length && IsNumeric(str[i])==true)
            {
                operand = (operand*10) + (str[i]-'0');
                i++;
            }
            stack[++top] = operand;
            i--;
        }
    }
    return (stack[top]);

}


enum boolean IsOperator(char st)
{
    if(st == '+' || st == '-' || st == '*' || st == '/')
        return (true);
    return (false);
}

enum boolean IsNumeric(char st)
{
    if(st>='0' && st<='9')
        return (true);
    return (false);
}










int DoOperation(char st, int num1, int num2)
{
    if(st == '+')
        return (num1 + num2);

    else if(st == '-')
        return (num1-num2);

    else if(st == '*')
        return (num1 * num2);

    else if(st == '/')
        return (num1/num2);
    else
    {
        printf("Unexpected error\n");
        exit(0);
    }

}






















