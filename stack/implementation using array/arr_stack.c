#include"stdio.h"

#define MAX_SIZE 101

int top = -1;
int arr[MAX_SIZE];

void main()
{
    int n;
    while(1)
    {
        system("cls");
        printf("What do you want to do?\n1. Push\n2. Pop\n3. Print\n4. Exit\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            print();
            break;

        case 4:
            exit(0);

        default: printf("Invalid Choice\n");
        }
        _getch();
    }
}



void push()
{
    int num;
    if (top == MAX_SIZE)
    {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter a number\n");
    scanf("%d",&num);
    arr[++top] = num;
}


void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

void print()
{
    int i;
    printf("Your final list is\n");
    if(top == -1)
    {
        printf("List is empty\n");
        return;
    }
    for(i = 0;i<=top;i++)
    {
        printf("%d ",arr[i]);
    }
}












