/*
Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 
*/

class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preIndex=0;
        return helper(pre, in, preIndex, 0, n-1);
    }
    
    Node* helper(int* pre, int* in, int &preIndex, int inStart, int inEnd)
    {
        if(inStart>inEnd)
        {
            return NULL;
        }
        
        Node* newNode = new Node(pre[preIndex]);
        preIndex++;
        
        if(inStart==inEnd)
        {
            return newNode;
        }
        
        int inIndex = search(in, inStart, inEnd, newNode->data);
        
        newNode->left = helper(pre, in, preIndex, inStart, inIndex-1);
        newNode->right = helper(pre, in, preIndex, inIndex+1, inEnd);
        
        return newNode;
    }
    
    int search(int* in, int start, int end, int val)
    {
        for(int i=start; i<=end; i++)
        {
            if(in[i]==val)
            {
                return i;
            }
        }
    }
};
