#include"stdio.h"
#include"stdlib.h"

void print_list(void);
void insert_node(void);

typedef struct
{
    int data;
    struct Node *next ;
}Node;

Node * create_node(void);

Node *start = NULL;

void main()
{
    int n;
    printf("Do you want to make a linked list?\n1. YES\n2. NO\n");
    scanf("%d",&n);
    while(1)
    {
        switch(n)
        {

            case 1:
                {

                insert_node();
                printf("Do you want to continue?\n1. YES\n2. NO\n");
                scanf("%d",&n);
                break;
                }

            case 2:{
                    print_list();
                    exit(0);
            }

            default:printf("Invalid selection\n");
            }
        }

}


Node * create_node()
{
    Node *n;
    n = (Node *)malloc(sizeof(Node));
    return(n);
}


void insert_node()
{
    Node *temp, *t;
    temp = create_node();
    temp->next = NULL;
    printf("Enter a number\n");
    scanf("%d",&temp->data);
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        t = start;
        while(t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
    }
}


void print_list()
{
    Node *p;
    printf("Your final linked list is \n");
    p = start;
    while(p->next != NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
    printf("%d\n",p->data);

}


















