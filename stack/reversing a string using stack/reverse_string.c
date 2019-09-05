#include"stdio.h"
#define SIZE 10000

char arr[SIZE];
int top =-1;

void main()
{
    char str[10000];
    printf("Input a string\n");
    scanf("%[^\n]",str);
    reverse_stack(str);
    printf("The reversed string using stack is:\n%s",str);
}

void reverse_stack(char str[])
{
    int i;
    for(i = 0;str[i];i++)
    {
        arr[++top] = str[i];
    }
    i = -1;
    while (top >= 0)
    {
        str[++i] = arr[top--];

    }
}
