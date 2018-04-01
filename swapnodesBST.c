void swapEveryKLevelUtil( Node *root, int level, int k)
{
    // base case
    if (root== NULL ||
            (root->left==NULL && root->right==NULL) )
        return ;
 
    //if current level + 1  is present in swap vector
    //then we swap left & right node
    if ( (level + 1) % k == 0)
        Swap(&root->left, &root->right);
 
    // Recur for left and right subtrees
    swapEveryKLevelUtil(root->left, level+1, k);
    swapEveryKLevelUtil(root->right, level+1, k);
}
 
// This function mainly calls recursive function
// swapEveryKLevelUtil()
void swapEveryKLevel(Node *root, int k)
{
    // call swapEveryKLevelUtil function with
    // initial level as 1.
    swapEveryKLevelUtil(root, 1, k);
}