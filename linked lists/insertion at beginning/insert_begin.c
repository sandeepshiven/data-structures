#include"stdio.h"
#include"stdlib.h"

typedef struct
{
    int data;
    struct Node *next;
}Node;

Node *start = 0;

void main()
{
    int n;
    while(1)
    {
        system("cls");
        printf("What do you want to do?\n1. Insert at beginning\n2. View list\n3. Exit\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insert();
            break;

        case 2:
            print_list();
            break;
        case 3 :
            exit(0);

        default:printf("Invalid selection\n");
        }
        _getch();

    }
}


Node *create_node()
{
    Node *n;
    n = (Node *)malloc(sizeof(Node));
    return(n);
}

void insert()
{
    Node *temp;
    temp = create_node();
    printf("Enter a number\n");
    scanf("%d",&temp->data);
    temp->next = start;
    start = temp;
}


void print_list()
{
    Node *p;
    p = start;
    printf("Your final list\n");
    if(p==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(p != NULL)
        {
            printf("%d\n",p->data);
            p = p->next;
        }
    }
}












