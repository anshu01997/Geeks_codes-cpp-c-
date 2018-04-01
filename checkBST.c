/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
bool checkBST(Node* root, Node* l=NULL, Node* r=NULL)
{
    // Base condition
    if (root == NULL)
        return true;
 
    // if left node exist that check it has
    // correct data or not
    if (l != NULL and root->data < l->data)
        return false;
 
    // if right node exist that check it has
    // correct data or not
    if (r != NULL and root->data > r->data)
        return false;
 
    // check recursively for every node.
    return checkBST(root->left, l, root) and
           checkBST(root->right, root, r);
}