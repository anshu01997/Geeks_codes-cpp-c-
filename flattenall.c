#include<stdio.h>
#include<stdlib.h>
typedef struct Node{     //use of typedef to change the structure format
  int data;
  struct Node *next;
} Node;
void push(struct Node** head_ref,int new_data)
{
  struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));

}
Node* merge(Node* a,Node* b)
{
  if(a==NULL)
    return b;
  if(b==NULL)
    return a;
  Node* result;
    if(a->data < b->data)
    {
      result = a;
      result->down = merge(a->down,b);
    }
    else{
      result = b;
      result->down = merge(a,b->down);
        }
        return result;
}
Node* flatten(Node* root)
{
  if(root==NULL || root->right==NULL)
    return root;
   return merge(root,flatten(root->right));  
}









int main()
{
  struct Node *root=NULL;
  push(&root,30);
  push(&root,8);
  push(&root,7);
  push(&root,5);
  push(&(root->right),20);
  push(&(root->right),10);
  push( &( root->right->right ), 50 );
  push( &( root->right->right ), 22 );
  push( &( root->right->right ), 19 );
  push( &( root->right->right->right ), 45 );
  push( &( root->right->right->right ), 40 );
  push( &( root->right->right->right ), 35 );
  push( &( root->right->right->right ), 20 );
  printlist(root);
  flatten(root);
  printlist(root);
  return (0);
}
