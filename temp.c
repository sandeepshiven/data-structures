BstNode *Search(BstNode *,int );
BstNode *InOrderSuccesor(BstNode *,int);

            case 14:{
                printf("Enter the value whose succesor you want: ");
                scanf("%d",data);
                printf("Inorder succersor of %d is: %d",data,InOrderSuccesor(root,data)->data);
                printf("\nPress any number and then hit enter\n");
                scanf("%d");
                break;
            }
            case 15:
            {
                exit(0);
            }

BstNode *Search(BstNode *root,int data)
{
    if(root == NULL)
    {
        return root;
    }
    if(root->data == data)
    {
        return root;
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

BstNode *InOrderSuccesor(BstNode *root, int value){
    BstNode *successor = NULL;
    BstNode *current = Search(root,value);
    if(current == NULL)
        return NULL;
    else if(current->right != NULL)
        return MinRecur(current->right);
    else{
        BstNode *ancestor = root;
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