#include"stdio.h"
#include"stdlib.h"

void insert_node(void);




typedef struct
{
    int data;
    struct Node *next;
}Node;

Node *create_node(void);
Node *head = NULL;


void main()
{
    int n;
    while(1)
    {
        system("cls");
        printf("What do you want to do?\n1. Insert\n2. Delete\n3. Display list\n4. Exit\n");
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
            exit(0);

        default:printf("Invalid choice\n");
        }
        _getch();
    }
}



Node *create_node()    //creating a node and returning its address
{
    Node *n;
    n = (Node *)malloc(sizeof(Node));
    return(n);
}




void insert_node()
{
    Node *temp1;
    temp1 = create_node();  //storing address of the new node
    temp1->next = NULL;     // making .next equal to null
    printf("Enter the number you want to insert\n");
    int num;
    scanf("%d",&num);
    temp1->data = num;  // storing the data in new node
    printf("Enter the position at which you want to insert\n");
    int pos,i;
    scanf("%d",&pos);

    if(pos == 1)  // checking if position to be inserted is first node or not
    {
        temp1->next = head;
        head = temp1; // storing the address of the new first node in head
        return;
    }

    Node *temp2 = head;
    for(i=0;i<pos-2;i++)
    {
        temp2 = temp2->next;  // (n-2)th element
    }
    temp1->next = temp2->next;  // storing the address of the (n)th element in .next of new node
    temp2->next = temp1;  // storing the address of the new node in the (n-1)th node



}


void delete_node()
{
    Node *temp = head;
    printf("Enter the position you want to delete\n");
    int i,pos;
    scanf("%d",&pos);
    if(pos == 1)
    {
        head = temp->next; // storing the address of the second element in head
        free(temp); //destroying the first node
        return;
    }
    Node *temp2;
    for(i=0;i<pos-2;i++)
    {
        temp = temp->next; //(n-2)th element
    }
    temp2 = temp->next;  //storing the address of (n)th element
    temp->next = temp2->next; //storing the address of the (n+1)th node in the (n-1)th node
    free(temp2); //destroying (n)th node
}






void print_list()
{
    Node *p = head;
    printf("Your final list is\n");
    if (p== NULL)
    {
        printf("List is empty\n");
    }
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}


















