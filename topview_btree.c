/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

/*void topView(node * root) {
    if(!root)
        return;
    if(root->left != 0)
        return (root);
    if(root->right != 0)
 
  
}*/
void topView(node * root) {
    
        if (root->left) {
            root->left->right = NULL;
            topView(root->left);
        }
    
        printf("%d ", root->data);
    
        if (root->right) {
            root->right->left = NULL;
            topView(root->right);
        }
    //printf("%d ",root->data);
    }
    
    