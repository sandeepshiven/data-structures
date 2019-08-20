#include"stdio.h"
#include"stdlib.h"

typedef struct
{
    int data;
    struct Node *next;
}Node;

Node *head = NULL;

void main()
{
    int n;
    while(1)
    {
        system("cls");
        printf("What do you want to do?\n1. Insert\n2. Print\n3. Print Reverse\n4. Exit\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insert_node();
            break;

        case 2:
            printf("You list is\n");
            print_list(head);
            break;

        case 3:
            printf("Your list reversed is\n");
            print_reverse(head);
            break;

        case 4:
            exit(0);

        default : printf("Invalid Choice\n");
        }
        _getch();
    }
}



void insert_node()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->next = NULL;
    printf("Enter a number\n");
    scanf("%d",&temp->data);
    if(head == NULL)
    {
        head = temp;
        return;
    }
    Node *temp2 = head;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}


void print_list(Node *p)
{
    if(p == NULL)
    {
        return;
    }
    printf("%d ",p->data);
    print_list(p->next);
}


void print_reverse(Node *p)
{
    if(p == NULL)
    {
        return;
    }
    print_reverse(p->next);
    printf("%d ",p->data);
}


























