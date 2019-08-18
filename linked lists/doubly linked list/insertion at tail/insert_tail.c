#include"stdio.h"
#include"stdlib.h"


typedef struct
{
    int data;
    struct Node *prev;
    struct Node *next;
}Node;

Node *head = NULL;

void main()
{
    int n;
    while(1)
    {
        system("cls");
        printf("What do you want to do?\n1. Insert\n2. Display\n3. Check double link\n4. Exit\nEnter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insert_node();
            break;

        case 2:
            print_list();
            break;

        case 3:
            check_double();
            break;

        case 4:
            exit(0);

        default:printf("Invalid choice\n");

        }
        _getch();


    }
}


Node *create_node()
{
    Node *n;
    n = (Node *)malloc(sizeof(Node));
    n->prev = NULL;
    n->next = NULL;
    return(n);
}



void insert_node()
{
    Node *temp;
    temp = create_node();

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
    temp->prev = temp2;

}

void print_list()
{
    Node *p = head;
    printf("Your final list is\n");
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}


void check_double()
{
    Node *p = head;
    printf("Your list reversed is\n");
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(p->next != NULL)
    {
        p = p->next;
    }

    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->prev;
    }
}


















