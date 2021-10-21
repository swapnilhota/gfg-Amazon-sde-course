/*
Given a Binary Tree. Check whether the Binary tree is a full binary tree or not.
*/

bool isFullTree (struct Node* root)
{
    if(root==NULL)
    {
        return false;
    }
    
    if(root->left==NULL && root->right==NULL)
    {
        return true;
    }
    
    if(root->left==NULL || root->right==NULL)
    {
        return false;
    }
    
    return isFullTree(root->left) && isFullTree(root->right);
}
