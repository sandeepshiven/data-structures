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
        printf("What do you want to do? \n1. Insertion\n2. Reversal\n3. Display\n4.Exit\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insert_node();
            break;

        case 2:
            reverse_list();
            break;

        case 3:
            print_list();
            break;

        case 4:
            exit(0);

        default:printf("Invalid selection\n");

        }
        _getch();
    }
}


Node *create_node()
{
    Node *n;
    n = (Node *)malloc(sizeof(n));
    return(n);
}


void insert_node()
{
    Node *temp,*temp2;
    temp = create_node();
    temp->next = NULL;
    printf("Enter a number\n");
    scanf("%d",&temp->data);
    if(head == NULL)
    {
        head = temp;
        return;
    }
    temp2 = head;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;

}


void reverse_list()
{
    Node *current,*prev,*next;

    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


void print_list()
{
    Node *p;
    p = head;
    printf("Your final list is\n");
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}














