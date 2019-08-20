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
        printf("What do you want to do?\n1. Insert\n2. Display\n3. Check double linking\n4. Exit\nEnter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insert_head();
            break;

        case 2:
            print_list();
            break;

        case 3:
            print_reverse();
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
    n->next = NULL;
    n->prev = NULL;
    return(n);
}


void insert_head()
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
    temp2->prev = temp;
    temp->next = temp2;
    head = temp;

}



void print_list()
{
    Node *p = head;
    printf("Your final list is \n");
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


void print_reverse()
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

























