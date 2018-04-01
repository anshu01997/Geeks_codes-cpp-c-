/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/
node *newnode(int item)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

node * insert(node * root, int value) {
    if(root==NULL)
        return newnode(value);
    if(value < root->data)
        root->left=insert(root->left,value);
    else if(value > root->data)
        root->right=insert(root->right,value);
     return root;
}
/*node * insert(node * root, int value)
{ if(root==NULL)
  {
    node *temp=(node *)malloc(sizeof(node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=value;
    root=temp;
  }
  else if(value <= root->data)
  {
      root->left=insert(root->left,value);
  }
  else
  {
     root->right=insert(root->right,value); 
  }

   return root;
}
*/