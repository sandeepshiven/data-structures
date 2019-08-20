#include"stdio.h"
#include"stdlib.h"

/*

creating program for inserting node in the last of
the list and deleting the item from the beginning
this is simple implementation of queue by
using linked list where the First in First out  approach
is used
*/






void print_list(void);
void insert_node(void);

typedef struct
{
    int data;
    struct Node *next ;
}Node;

Node * create_node(void);

Node *start = NULL;  //creating start for accessing the list

void main()
{
    int n;
    while(1)
    {
        system("cls");
        printf("Do you want to do?\n1. Insert at the end\n2. Delete from the beginning\n3. Display\n4. Exit\n");
        scanf("%d",&n);
        switch(n)
        {

            case 1:
                {

                insert_node();
                break;
                }

            case 2:{
                    delete_node();
                    break;
            }
            case 3:
                print_list();
                break;

            case 4:
                exit(0);
                break;

            default:printf("Invalid selection\n");
            }
            _getch();
        }

}


Node * create_node()  // creating a node and returning its address
{
    Node *n;
    n = (Node *)malloc(sizeof(Node));
    return(n);
}


void insert_node()
{
    Node *temp, *t;
    temp = create_node();
    temp->next = NULL;  // putting null in next for every new node created
    //system("cls");
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
        t->next = temp;  // putting the address of newly created node in the last node thus making it second last
    }
}


void print_list()
{
    Node *p;
    //system("cls");
    printf("Your final linked list is \n");
    p = start;
    if (p == NULL)
    {
        printf("List is empty\n");
    }
    else
    {

    while(p->next != NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
    printf("%d\n",p->data);  // the last node doesn't get printed in the loop
    }                         // because p->next becomes null for the last node and loop ends

}

void delete_node()
{
    Node *d;
    d = start;
    if(d == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        start = start->next;
        free(d);
    }
}















