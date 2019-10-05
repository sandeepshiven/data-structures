#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#include <limits.h>


typedef struct{
    int data;
    struct BstNode *right;
    struct BstNode *left;
}BstNode;

// queue for storing address
BstNode *queue[1000];
int front = -1;
int rear = -1;

void push(BstNode *);
void pop();
BstNode *front_data();
int isEmpty();
// ends here 

int Search(BstNode *,int );
BstNode *Insert(BstNode *,int );
BstNode *GetNewNode(int );
int MinIter(BstNode *);
BstNode *MinRecur(BstNode *);
int MaxIter(BstNode *);
BstNode *MaxRecur(BstNode *);
int MaxHeight(BstNode *);
int LevelOrder(BstNode *);
int PreOrder(BstNode *);
int InOrder(BstNode *);
int PostOrder(BstNode *);
int IsBst(BstNode *);
int IsSubGreater(BstNode *, int);
int IsSubLesser(BstNode *, int);
int IsBstB(BstNode *);
int IsBstUtil(BstNode *,int ,int );
BstNode *DeleteNode(BstNode * , int);


void main(){
    BstNode *root = NULL;
    int choice,data;
    char temp;
    while(1){
        system("clear");
        printf("What do you want to do?\n1. Insert\n2. Search\n3. Min(iter)\n4. Min(recursive)\n");
        printf("5. Max(iter)\n6. Max(recursive)\n7. Height\n8. Level order\n9. Pre Order\n");
        printf("10. In Order\n11. Post Order\n12. Check Bst(Good)\n13. Check Bst(Better)\n");
        printf("14. Delete Node\n15. Exit\nEnter your Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{   
                fflush(stdin);
                printf("Enter the data\n");
                scanf("%d",&data);
                root = Insert(root,data);
                break;
            }
            case 2:{
                fflush(stdin);
                printf("Enter the element you want to search\n");
                scanf("%d",&data);
                if (Search(root,data)){
                    printf("Data Found\n");
                    fflush(stdin);
                    printf("Press any number and then hit enter\n");
                    scanf("%d");
                    break;
                }               
                else{
                    printf("Not Found\n");
                    fflush(stdin);
                    printf("Press any number and then hit enter\n");
                    scanf("%d");
                    break;
                }
            }

            case 3:{
                printf("Min element using iterative: %d\n",MinIter(root));
                printf("Press any number and then hit enter\n");
                scanf("%d");
                break;

            }

            case 4:{
                printf("Min element using recursive: %d\n",MinRecur(root)->data);
                printf("Press any number and then hit enter\n");
                scanf("%d");
                break;

            }

            case 5:{
                printf("Max element using iterative: %d\n",MaxIter(root));
                printf("Press any number and then hit enter\n");
                scanf("%d");
                break;

            }
            case 6:{
                printf("Max element using recursive: %d\n",MaxRecur(root)->data);
                printf("Press any number and then hit enter\n");
                scanf("%d");
                break;

            }

            case 7:{
                printf("Max height of the tree is: %d\n",MaxHeight(root));
                printf("Press any number and then hit enter\n");
                scanf("%d");
                break;
            }
            
            case 8:{
                printf("The result of level order traversal:\n");
                LevelOrder(root);
                printf("\nPress any number and then hit enter\n");
                scanf("%d");
                break;
            }

            case 9:{
                printf("The result of Pre order traversal:\n");
                PreOrder(root);
                printf("\nPress any number and then hit enter\n");
                scanf("%d");
                break;
            }

            case 10:{
                printf("The result of In order traversal:\n");
                InOrder(root);
                printf("\nPress any number and then hit enter\n");
                scanf("%d");
                break;
            }

            case 11:{
                printf("The result of Post order traversal:\n");
                PostOrder(root);
                printf("\nPress any number and then hit enter\n");
                scanf("%d");
                break;
            }

            case 12:{
                if(IsBst(root)){
                    printf("Tree is Binary Search Tree");
                }
                else{
                    printf("Not a Binary Search Tree");
                }
                printf("\nPress any number and then hit enter\n");
                scanf("%d");
                break;
                
            }

            case 13:{
                if(IsBstB(root)){
                    printf("Tree is Binary Search Tree");
                }
                else{
                    printf("Not a Binary Search Tree");
                }
                printf("\nPress any number and then hit enter\n");
                scanf("%d");
                break;
            }
            case 14:{
                printf("Enter the data you want to delete: ");
                scanf("%d",&data);
                root = DeleteNode(root,data);
                break;
            }
            case 15:{
                exit(0);
            }

            default:{
                printf("Invalid Choice");
            }
        }
    }

}

BstNode *GetNewNode(int data){
    BstNode *root = (BstNode *)malloc(sizeof(BstNode));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}


BstNode *Insert(BstNode *root,int data){
    if (root == NULL){
        root = GetNewNode(data);
    }
    else if(data <= root->data){
        root->left = Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right,data);
    }
    return root;
    
}

int Search(BstNode *root,int data){
    if(root == NULL){
        return 0;
    }
    if(root->data == data){
        return 1;
    }
    else if(data <= root->data){
        return Search(root->left,data);
    }
    else{
        return Search(root->right,data);
    }
}

int MinIter(BstNode *root){
    if(root == NULL){
        printf("Tree is Empty\n");
        return -999999;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

int MaxIter(BstNode *root){
    if(root == NULL){
        printf("Tree is Empty\n");
        return -999999;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

BstNode *MinRecur(BstNode *root){
    if(root == NULL){
        printf("Tree is Empty\n");
        return NULL;
    }
    else if(root->left == NULL){
        return root;
    }
    else{
        return MinRecur(root->left);
    }
    
}

BstNode *MaxRecur(BstNode *root){
    if(root == NULL){
        printf("Tree is Empty\n");
        return NULL;
    }
    else if(root->right == NULL){
        return root;
    }
    else{
        return MaxRecur(root->right);
    }
    
}

int MaxHeight(BstNode *root){
    int left_height,right_height,max;
    if (root == NULL){
        return -1;
    }
    /*
    left_height = MaxHeight(root->left);
    right_height = MaxHeight(root->right);
    max = left_height > right_height ?left_height:right_height;
    return (max + 1);
    */
    //can also do this but not easily readable

//    max = MaxHeight(root->left) > MaxHeight(root->right)?MaxHeight(root->left) : MaxHeight(root->right); 
  //  return (max +1);

    //or

    return ((MaxHeight(root->left) > MaxHeight(root->right)?MaxHeight(root->left) : MaxHeight(root->right))+1);    

    

}

// queue functions starts here
void push(BstNode *root){
    if (front == -1)
        front++;
    queue[++rear] = root;
}

void pop(){
    front++;
}

BstNode *front_data(){
    return queue[front];
}

int isEmpty(){
    if(front > rear)
        return 1;
    return 0;
}


//ends here

int LevelOrder(BstNode *root){
    BstNode *current;
    if(root == NULL){
        printf("Tree is Empty");
        return -99999;
    }

    push(root);
    while(!isEmpty()){
        current = front_data();
        printf("%d ",current->data);

        if (current->left != NULL){
            push(current->left);
        }

        if (current->right != NULL){
            push(current->right);
        }
        pop();
    }
    return 1;

}

int PreOrder(BstNode *root){
    if (root == NULL)
        return 0;
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

int InOrder(BstNode *root){
    if (root == NULL)
        return 0;
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}

int PostOrder(BstNode *root){
    if (root == NULL)
        return 0;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->data);
}


int IsBst(BstNode *root){
    if(root == NULL){
        return 1;
    }
    if(IsSubLesser(root->left,root->data) && IsSubGreater(root->right,root->data)&& IsBst(root->left) && IsBst(root->right))
        return 1;
    return 0;
}

int IsSubLesser(BstNode *root, int value){
    if(root == NULL)
        return 1;

    if((value >= root->data) && IsSubLesser(root->left,value) && IsSubLesser(root->right,value))
        return 1;
    
    return 0;
}

int IsSubGreater(BstNode *root, int value){
    if(root == NULL)
        return 1;

    if((value <= root->data) && IsSubGreater(root->left,value) && IsSubGreater(root->right,value))
        return 1;
    
    return 0;
}


int IsBstB(BstNode *root){
    return IsBstUtil(root,INT_MAX,INT_MIN);

}


int IsBstUtil(BstNode *root,int max,int min){
    if(root == NULL)
        return 1;
    if((root->data > min) && (root->data < max) && IsBstUtil(root->left,root->data,min) && IsBstUtil(root->right,max,root->data))
        return 1;
    return 0;
}

BstNode *DeleteNode(BstNode *root, int value){
    if(root == NULL){
        return NULL;
    }
    else if(root->data > value){
        root->left = DeleteNode(root->left,value);
    }
    else if(root->data < value){
        root->right = DeleteNode(root->right,value);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if(root->left == NULL){
            BstNode *temp = root;
            root = temp->right;
            free(temp);
        }
        else if(root->right == NULL){
            BstNode *temp = root;
            root = temp->left;
            free(temp);
        }
        else{
            BstNode *temp = MaxRecur(root->left);
            root->data = temp->data;
            root->left = DeleteNode(root->left,root->data);
        }
    }
    return root;
}
