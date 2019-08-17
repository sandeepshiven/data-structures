#include<stdio.h>
#include<stdlib.h>


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
       //system("clear");
       system("cls");
       printf("What do you want to do?\n1. Insert\n2. Reverse\n3. Display\n4. Exit\n");
       scanf("%d",&n);
       switch(n)
       {
            case 1:
                insert();
                break;

            case 2:
                recursive_reverse(head);
                break;

            case 3:
                print_list();
                break;

            case 4:
                exit(0);

            default: printf("Invalid Choice\n");
       }
       _getch();
    }
}



void insert()
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

void recursive_reverse(Node *p)
{
    if(p->next == NULL)
    {
        head = p;
        return;
    }

    recursive_reverse(p->next);
    Node *temp = p->next;
    temp->next = p;
    p->next = NULL;

}

void print_list()
{
    Node *p = head;
    printf("Your final list is\n");
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

















