
#include"stdio.h"
#define MAX 1000

typedef struct
{
    int data;
    struct Node *next;
}Node;

Node *head = NULL;
Node stack[MAX];

void main()
{
    int n;
    while(1)
    {
        printf("What do you want to do?\n1. Insert\n2. Print\n3. Reverse\n4. Exit\n");
        scanf("%d",&n);
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
        _getch();
    }
}


void insert()
{
    int num;
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->next = NULL
    printf("Enter a number\n");
    scanf("%d",&temp->data);
    if(head == NULL)
    {
        head = temp;
        return;
    }
    temp1 = head;
    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;

}

void reverse()
{
    int i;
    Node *prev=NULL;
    Node *temp = head;
    while(temp)
    {
        stack[i++]->next=temp;
        prev = temp;
        temp = temp->next;
    }
    head->next = NULL;
    head = prev;

    while(temp)
    {

    }




}




