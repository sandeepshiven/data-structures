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
            delete_node();
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
    Node *temp1,*temp2 = head;
    int pos,i;
    temp1 = create_node();

    printf("Enter a number\n");
    scanf("%d",&temp1->data);
    printf("Enter the position you want to insert\n");
    fflush(stdin);
    scanf("%d",&pos);

    if(pos == 1)
    {
        temp1->next = head;
        if(head != NULL)
            temp2->prev = temp1;
        head = temp1;
        return;
    }

    for(i= 0;i<pos-2;i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp1->prev = temp2;
    temp2->next = temp1;
    temp2 = temp1->next;
    if(temp2 != NULL)
        temp2->prev = temp1;

}

void delete_node()
{
    int pos,i;
    Node *del = head,*del2 = del->next;
    printf("Enter the position you want to delete\n");
    scanf("%d",&pos);
    if(pos == 1)
    {
        head = del->next;
        del2->prev = NULL;
        free(del);
        return;
    }
    for(i=0;i<pos-2;i++)
    {
        del = del->next;
    }
    del2 = del->next;
    del->next = del2->next;
    del = del2->next;
    if(del != NULL)
        del->prev = del2->prev;
    free(del2);

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





















