#include"stdio.h"
#include"stdlib.h"

typedef struct
{
    int data;
    struct Node *next;
}Node;

Node *top = NULL;

void main()
{
    int n;
    while(1)
    {
        system("cls");
        printf("What do you want to do?\n1. Push\n2. Pop\n3. Top\n4. Exit\n");
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
            stack_top();
            break;

        case 4:
            exit(0);

        default : printf("Invalid choice\n");
        }
        _getch();
    }
}


void push()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    int num;

    temp->next = NULL;
    printf("Enter a number\n");
    scanf("%d",&temp->data);

    temp->next = top;
    top = temp;
}

void pop()
{
    Node *temp = top;
    if (top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    top = temp->next;
    free(temp);
}


void stack_top()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top of the stack is: %d",top->data);
}
























