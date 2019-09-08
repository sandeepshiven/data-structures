
#include"stdio.h"
#define MAX 1000
#include"conio.h"
#include"stdlib.h"



typedef struct
{
    int data;
    struct Node *next;
}Node;

Node *head = NULL;
Node *stack[MAX];



void main()
{
    int n;
    while(1)
    {
        fflush(stdin);
        system("clear");
        printf("\nWhat do you want to do?\n1. Insert\n2. Print\n3. Reverse\n4. Exit\n");
        scanf("%d",&n);
        fflush(stdin);
        switch(n)
        {
        case 1:
            insert();
            break;

        case 2:
            print();
            break;

        case 3:
            reverse();
            break;

        case 4:
            exit(0);

        default: printf("Invalid selection\n");

        }
        getch();
    }
}


void insert()
{
    int num;
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->next = NULL;
    fflush(stdin);
    printf("Enter a number\n");
    scanf("%d",&temp->data);
    fflush(stdin);
    if(head == NULL)
    {
        stack[0] = NULL;
        head = temp;
        return;
    }
    Node *temp1 = head;
    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;

}

void reverse()
{
    int top = 0;
    Node *temp1 = head;
    while(temp1)
    {
        stack[++top] = temp1;
        temp1 = temp1->next;
    }

    Node *temp = stack[top--];
    head = temp;
    while(temp)
    {
        temp->next = stack[top--];
        temp = temp->next;
    }


}

void print()
{
    Node *temp = head;
    if (head == NULL)
    {
        printf("List Empty\n");
        return;
    }

    while(temp)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}


