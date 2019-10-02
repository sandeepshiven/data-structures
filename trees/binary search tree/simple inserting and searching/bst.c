#include"stdio.h"
#include"stdlib.h"
#include"conio.h"

typedef struct{
    int data;
    struct BstNode *right;
    struct BstNode *left;
}BstNode;


int Search(BstNode *,int );
BstNode *Insert(BstNode *,int );
BstNode *GetNewNode(int );




void main()
{
    BstNode *root = NULL;
    int choice,data;
    char temp;
    while(1)
    {
        system("clear");
        printf("What do you want to do?\n1. Insert\n2. Search\n3. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {   
                fflush(stdin);
                printf("Enter the data\n");
                scanf("%d",&data);
                root = Insert(root,data);
                break;
            }
            case 2:
            {
                fflush(stdin);
                printf("Enter the element you want to search\n");
                scanf("%d",&data);
                if (Search(root,data))
                {
                    printf("Data Found\n");
                    fflush(stdin);
                    printf("Press any number and then hit enter\n");
                    scanf("%d");
                    break;
                }               
                else
                {
                    printf("Not Found\n");
                    fflush(stdin);
                    printf("Press any number and then hit enter\n");
                    scanf("%d");
                    break;
                }
            }
            
            case 3:
            {
                exit(0);
            }

            default:
            {
                printf("Invalid Choice");
            }
        }
    }

}

BstNode *GetNewNode(int data)
{
    BstNode *root = (BstNode *)malloc(sizeof(BstNode));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}


BstNode *Insert(BstNode *root,int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left,data);
    }
    else
    {
        root->right = Insert(root->right,data);
    }
    return root;
    
}

int Search(BstNode *root,int data)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->data == data)
    {
        return 1;
    }
    else if(data <= root->data)
    {
        return Search(root->left,data);
    }
    else
    {
        return Search(root->right,data);
    }
}










