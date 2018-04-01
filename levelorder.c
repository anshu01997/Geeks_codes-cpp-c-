
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/
int height(node * root)
{
  if(!root)
      return 0;
    int lleft=height(root->left);
    int rright=height(root->right);
    if(lleft > rright)
        return(lleft+1);
    else
        return (rright+1);
}
  void level(node *root,int h){
      if(!root)
          return ;
      if(h==1)
          cout<<root->data<<" ";
      level(root->left,h-1);
      level(root->right,h-1);
  }
void LevelOrder(node * root)
{
  int n=height(root);
    for(int i=1;i<=n;i++){
        level(root,i);
        
    }
  
}