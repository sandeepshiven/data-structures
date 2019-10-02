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
int MinIter(BstNode *);
int MinRecur(BstNode *);
int MaxIter(BstNode *);
int MaxRecur(BstNode *);



void main()
{
    BstNode *root = NULL;
    int choice,data;
    char temp;
    while(1)
    {
        system("clear");
        printf("What do you want to do?\n1. Insert\n2. Search\n3. Min(iter)\n4. Min(recursive)\n");
        printf("5. Max(iter)\n6. Max(recursive)\n7. Exit\nEnter your choice: ");
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
                printf("Min element using iterative: %d\n",MinIter(root));
                printf("Press any number and then hit enter\n");
                scanf("%d");
                break;

            }

            case 4:
            {
                printf("Min element using recursive: %d\n",MinRecur(root));
                printf("Press any number and then hit enter\n");
                scanf("%d");
                break;

            }

            case 5:
            {
                printf("Max element using iterative: %d\n",MaxIter(root));
                printf("Press any number and then hit enter\n");
                scanf("%d");
                break;

            }
            case 6:
            {
                printf("Max element using recursive: %d\n",MaxRecur(root));
                printf("Press any number and then hit enter\n");
                scanf("%d");
                break;

            }

            case 7:
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

int MinIter(BstNode *root)
{
    if(root == NULL)
    {
        printf("Tree is Empty\n");
        return -999999;
    }
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int MaxIter(BstNode *root)
{
    if(root == NULL)
    {
        printf("Tree is Empty\n");
        return -999999;
    }
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int MinRecur(BstNode *root)
{
    if(root == NULL)
    {
        printf("Tree is Empty\n");
        return -999999;
    }
    else if(root->left == NULL)
    {
        return root->data;
    }
    else
    {
        return MinRecur(root->left);
    }
    
}

int MaxRecur(BstNode *root)
{
    if(root == NULL)
    {
        printf("Tree is Empty\n");
        return -999999;
    }
    else if(root->right == NULL)
    {
        return root->data;
    }
    else
    {
        return MaxRecur(root->right);
    }
    
}

