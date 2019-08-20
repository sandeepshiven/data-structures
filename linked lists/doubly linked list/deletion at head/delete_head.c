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
        printf("What do you want to do?\n1. Insert\n2. Delete\n3. Display\n4. Check double link\n5. Exit\nEnter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insert_node();
            break;

        case 2:
            delete_head();
            break;

        case 3:
            print_list();
            break;

        case 4:
            check_double();
            break;

        case 5:
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

void delete_head()
{
    Node *del = head;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *del2 = del->next;
    head = del->next;
    del2->prev = NULL;
    free(del);

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



















