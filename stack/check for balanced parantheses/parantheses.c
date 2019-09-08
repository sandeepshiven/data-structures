#include"stdio.h"
#include"stdlib.h"
#define MAX 1000
#include"string.h"

char stack[MAX];
int top = -1;

void main()
{
    char string[1000];
    int result;

        //system("clear");
        printf("\nEnter your expression:\n");
        fflush(stdin);
        gets(string);
        result= balance_check(string);
        if (result == 1)
            printf("Balanced\n");
        else
            printf("Not balanced\n");

}


int balance_check(char str[])
{
    int i;
    int length = strlen(str);
    //printf("length = %d\n",length);
    for(i=0;i<length;i++)
    {
        //printf("str[%d] = %c\n",i,str[i]);
        //printf("stack[%d] = %c\n",top,stack[top]);
        if(str[i] == '[' || str[i] == '{' || str[i] == '(')
        {
            stack[++top] = str[i];
        }


        else if(str[i] == ']' || str[i] == '}' || str[i] == ')')
        {
            //printf("str[i]-2 = %c",str[i]-1);
            if((str[i]-2 == stack[top]) || (str[i]-1 == stack[top]))
            {
                top--;
            }
            else
                return 0;
        }

    }

    if (top == -1)
        return 1;
    else
        return 0;
}












