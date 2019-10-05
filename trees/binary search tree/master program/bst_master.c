#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#include <limits.h>


typedef struct{  // Making a bst node with atributes data in node address of the left child and address of right child
    int data;
    struct BstNode *right;
    struct BstNode *left;
}BstNode;

// queue for storing address // this queue is used in level order traversal
BstNode *queue[1000];
int front = -1;
int rear = -1;

void push(BstNode *); // go to line 319 
void pop(); // go to line 325 
BstNode *front_data(); // go to line 329
int isEmpty(); // go to line 333
// ends here 

BstNode *Search(BstNode *,int ); // go to line 229
BstNode *Insert(BstNode *,int ); // go to line 215
BstNode *GetNewNode(int ); // go to line 206
int MinIter(BstNode *); // go to line 244
BstNode *MinRecur(BstNode *); // go to line 266
int MaxIter(BstNode *); // go to line 255
BstNode *MaxRecur(BstNode *); // go to line 280
int MaxHeight(BstNode *); // go to line 294
int LevelOrder(BstNode *); // go to line 342
int PreOrder(BstNode *); // go to line 367
int InOrder(BstNode *); // go to line 375
int PostOrder(BstNode *); // go to line 383
int IsBst(BstNode *); // go to line 392
int IsSubGreater(BstNode *, int); // go to line 411
int IsSubLesser(BstNode *, int); // go to line 401
int IsBstB(BstNode *); // go to line 422
int IsBstUtil(BstNode *,int ,int ); // go to line 428
BstNode *DeleteNode(BstNode * , int); // go to line 436
BstNode *InOrderSuccesor(BstNode *,int); // go to line 470


void main(){
    BstNode *root = NULL;
    int choice,data;
    char temp;
    while(1){
        system("clear");
        printf("What do you want to do?\n1. Insert\n2. Search\n3. Min(iter)\n4. Min(recursive)\n");
        printf("5. Max(iter)\n6. Max(recursive)\n7. Height\n8. Level order\n9. Pre Order\n");
        printf("10. In Order\n11. Post Order\n12. Check Bst(Good)\n13. Check Bst(Better)\n");
        printf("14. Delete Node\n15. Inorder Successor\n16. Exit\nEnter your Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{   
                fflush(stdin);
                printf("Enter the data\n");
                scanf("%d",&data);
                root = Insert(root,data); // jump to 215
                break;
            }
            case 2:{
                fflush(stdin);
                printf("Enter the element you want to search\n");
                scanf("%d",&data);
                if (Search(root,data)){ // returns address  // jump to 229
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
                printf("Min element using iterative: %d\n",MinIter(root)); // returns integer  // jump to 244
                printf("Press any number and then hit enter\n");
                scanf("%d");
                break;

            }

            case 4:{
                printf("Min element using recursive: %d\n",MinRecur(root)->data); // returns address // jump to 266
                printf("Press any number and then hit enter\n");
                scanf("%d");
                break;

            }

            case 5:{
                printf("Max element using iterative: %d\n",MaxIter(root));//returns int // jump to 255
                printf("Press any number and then hit enter\n");
                scanf("%d");
                break;

            }
            case 6:{
                printf("Max element using recursive: %d\n",MaxRecur(root)->data);// returns address // jump to 280
                printf("Press any number and then hit enter\n");
                scanf("%d");
                break;

            }

            case 7:{
                printf("Max height of the tree is: %d\n",MaxHeight(root));// returns int // jump to 294
                printf("Press any number and then hit enter\n");
                scanf("%d");
                break;
            }
            
            case 8:{
                printf("The result of level order traversal:\n");
                LevelOrder(root); // prints data according to level // jump to 342
                printf("\nPress any number and then hit enter\n");
                scanf("%d");
                break;
            }

            case 9:{
                printf("The result of Pre order traversal:\n");
                PreOrder(root);// prints data according to DATA,LEFT,RIGHT(DLR) // jump to 367
                printf("\nPress any number and then hit enter\n");
                scanf("%d");
                break;
            }

            case 10:{
                printf("The result of In order traversal:\n");
                InOrder(root);// prints data according to LEFT,DATA,RIGHT(LDR) // jump to 375
                printf("\nPress any number and then hit enter\n");
                scanf("%d");
                break;
            }

            case 11:{
                printf("The result of Post order traversal:\n");
                PostOrder(root);// prints data according to LEFT,RIGHT,DATA(LRD) // jump to 383
                printf("\nPress any number and then hit enter\n");
                scanf("%d");
                break;
            }

            case 12:{
                if(IsBst(root)){ // returns int // complexity O(n^2) // jump to 392
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
                if(IsBstB(root)){// returns int // complexity O(n) // jump to 422
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
                root = DeleteNode(root,data);// delets the node while maintaining bst properties
                break; // returns address of root of changed bst // jump to 436
            }

            case 15:{
                printf("Enter the value whose succesor you want: ");
                scanf("%d",&data);
                printf("Inorder succersor of %d is: %d",data,InOrderSuccesor(root,data)->data);// finds the 
                printf("\nPress any number and then hit enter\n");// next element coming in Inorder Traversal
                scanf("%d");// and returns the address // jump to 470
                break;
            }
            case 16:
            {
                exit(0);
            }

            default:{
                printf("Invalid Choice");
            }
        }
    }

}

BstNode *GetNewNode(int data){ // creating a new node and returning its address
    BstNode *root = (BstNode *)malloc(sizeof(BstNode));
    root->data = data; // storing data in new node
    root->left = NULL;// default value of left and right child is NULL
    root->right = NULL;
    return root;
}


BstNode *Insert(BstNode *root,int data){ // inserting data in tree
    if (root == NULL){
        root = GetNewNode(data); // if node is empty then get new node
    }
    else if(data <= root->data){
        root->left = Insert(root->left,data); // recursive call if data to be inserted is less than the value
    }  // of current node then insert node as left child
    else{
        root->right = Insert(root->right,data);// recursive call if data to be inserted is greater than the value
    }// of current node then insert node as right child
    return root; // return the address of the root
    
}

BstNode *Search(BstNode *root,int data){ // searches required data and returns address of node
    if(root == NULL){ // if tree is empty returns null
        return root;
    }
    if(root->data == data){ // if data found return node address
        return root;
    }
    else if(data <= root->data){  // if data is less or equal to the data in current node the search again
        return Search(root->left,data); // in left subtree
    }
    else{
        return Search(root->right,data);  // if data is greater then search in right subtree
    }
}

int MinIter(BstNode *root){  // finding minimum value in tree using iteration
    if(root == NULL){
        printf("Tree is Empty\n");
        return -999999;
    }
    while(root->left != NULL){ // minimum value in bst will be the left most node of tree
        root = root->left;
    }
    return root->data;
}

int MaxIter(BstNode *root){ // finding maximum value in tree using iteration
    if(root == NULL){
        printf("Tree is Empty\n");
        return -999999;
    }
    while(root->right != NULL){ // maximum value in a bst will be the right most node of tree
        root = root->right;
    }
    return root->data;
}

BstNode *MinRecur(BstNode *root){ // finding minimum using recursion and returning address of the minimum node
    if(root == NULL){
        printf("Tree is Empty\n");
        return NULL;
    }
    else if(root->left == NULL){ // if the node is leftmost then there will no left child
        return root;
    }
    else{
        return MinRecur(root->left);  // recursive call to go to the left most node
    }
    
}

BstNode *MaxRecur(BstNode *root){ // finding maximum using recursion and returning address of the maximum node
    if(root == NULL){
        printf("Tree is Empty\n");
        return NULL;
    }
    else if(root->right == NULL){ // the right most node will  not have any right child
        return root;
    }
    else{
        return MaxRecur(root->right); // recursive call to go to the right most node
    }
    
}

int MaxHeight(BstNode *root){  // finding maximum height
    int left_height,right_height,max;
    if (root == NULL){
        return -1;
    }
    /* start reading from here
    left_height = MaxHeight(root->left); // calculating the height of the left subtree 
    right_height = MaxHeight(root->right); // calculating the height of the right subtree
    max = left_height > right_height ?left_height:right_height; // max height will be the max height of either
    return (max + 1); // left subtree or right subtree and to count the missing edge between root and subtree
    */                // add 1 and return
    //can also do this but not easily readable

//    max = MaxHeight(root->left) > MaxHeight(root->right)?MaxHeight(root->left) : MaxHeight(root->right); 
  //  return (max +1);

    //or

    return ((MaxHeight(root->left) > MaxHeight(root->right)?MaxHeight(root->left) : MaxHeight(root->right))+1);    

    

}

// queue functions starts here
void push(BstNode *root){ // implementation of a simple queue for storing the address of the nodes
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

int isEmpty(){ // checks if queue is empty or not
    if(front > rear)
        return 1;
    return 0;
}


//ends here

int LevelOrder(BstNode *root){  // prints the values in nodes according to 
    BstNode *current;
    if(root == NULL){
        printf("Tree is Empty");
        return -99999;
    }

    push(root); // pushing the address of the root on to the queue
    while(!isEmpty()){ // looping until the queue is empty
        current = front_data();  // storing the address in the front of the queue in current
        printf("%d ",current->data); // printing data

        if (current->left != NULL){
            push(current->left);  // storing address of the left child if present
        }

        if (current->right != NULL){
            push(current->right); // storing address of the right child if present
        }
        pop(); // finally poping out the element from the front of the queue
    }
    return 1;

}

int PreOrder(BstNode *root){ // printing the data according to preorder(Data,Left,right)
    if (root == NULL)
        return 0;
    printf("%d ",root->data); // data in current node
    PreOrder(root->left); // recursive call goes on until left subtree is finished
    PreOrder(root->right); // recursive call goes on until right subtree is finished
}

int InOrder(BstNode *root){ // printing the data according to Inorder(Left,Data,Right)
    if (root == NULL)
        return 0;
    InOrder(root->left);// recursive call goes on until left subtree is finished
    printf("%d ",root->data); // data in current node
    InOrder(root->right);// recursive call goes on until right subtree is finished
}

int PostOrder(BstNode *root){// printing the data according to Postorder(Left,right,Data)
    if (root == NULL)
        return 0;
    PostOrder(root->left);// recursive call goes on until left subtree is finished
    PostOrder(root->right);// recursive call goes on until right subtree is finished
    printf("%d ",root->data);// data in current node
}


int IsBst(BstNode *root){  // checking if tree is bst or not  // time complexity O(n^2)
    if(root == NULL){  // leaf node condition
        return 1;
    }
    if(IsSubLesser(root->left,root->data) && IsSubGreater(root->right,root->data)&& IsBst(root->left) && IsBst(root->right))
        return 1; // values in left subtree should be lesser than root //values in right subtree should be greater than root
    return 0;// left and right right subtrees should also be a bst
}

int IsSubLesser(BstNode *root, int value){ // checking if entier left subtree is less than the value root node
    if(root == NULL)
        return 1;

    if((value >= root->data) && IsSubLesser(root->left,value) && IsSubLesser(root->right,value))
        return 1;
    
    return 0;
}

int IsSubGreater(BstNode *root, int value){
    if(root == NULL) // checking if entier right subtree is greater than the value in root node
        return 1;

    if((value <= root->data) && IsSubGreater(root->left,value) && IsSubGreater(root->right,value))
        return 1;
    
    return 0;
}


int IsBstB(BstNode *root){ // checkin tree is bst or not // time complexity O(n)
    return IsBstUtil(root,INT_MAX,INT_MIN); 

}


int IsBstUtil(BstNode *root,int max,int min){ // this function checks if the value in a node is in between
    if(root == NULL)                    // specific range or not 
        return 1;
    if((root->data > min) && (root->data < max) && IsBstUtil(root->left,root->data,min) && IsBstUtil(root->right,max,root->data))
        return 1;
    return 0;
}

BstNode *DeleteNode(BstNode *root, int value){ // deleting node from a bst a trickier program
    if(root == NULL){
        return NULL;
    }
    else if(root->data > value){  // if the value to be deleted is less than current node the go to left subtree
        root->left = DeleteNode(root->left,value);// for the deletion
    }
    else if(root->data < value){  // same for right sub tree
        root->right = DeleteNode(root->right,value);
    }
    else{
        if(root->left == NULL && root->right == NULL){  // case 1: node is leaf node
            free(root); // then just simply delete it
            root = NULL;
        }
        else if(root->left == NULL){  // case 2: Node with only one child // code if only the left subtree is null
            BstNode *temp = root; // store the node in some var and rearrange the links then free the var
            root = temp->right;
            free(temp);
        }
        else if(root->right == NULL){ // case 2: CODE if only right child is null
            BstNode *temp = root;
            root = temp->left;
            free(temp);
        }
        else{ // trickier case 3: IF  node have two children // two approaches can work here first find the
            BstNode *temp = MaxRecur(root->left); // maximum value in left subtree and replace the value of current
            root->data = temp->data;// node with it and then delete that maximum value now maximum value will not  
            root->left = DeleteNode(root->left,root->data);// have any right child to it
        }  // same process can be done by finding minimum value of right subtree and repeating the process
    }
    return root;
}

BstNode *InOrderSuccesor(BstNode *root, int value){ // inorder successor the value which comes after a given
    BstNode *successor = NULL;                      // data in inorder traversal
    BstNode *current = Search(root,value);
    if(current == NULL)
        return NULL;
    else if(current->right != NULL) // case 1: if there is right subtree of the node then minimum of the subtree
        return MinRecur(current->right);// will come in inorder traversal
    else{  // case 2: if there is no right subtree of the node then we have keep track of the ancestor of the
        BstNode *ancestor = root; // the node which is not visited yet
        while(ancestor != current){
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
            
        }
    }
    return successor;
}