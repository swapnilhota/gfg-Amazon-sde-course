/*
Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines starting from left-most vertical line to right-most vertical line.
*/

class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        map<int, int> mp;
        helper(root, 0, mp);
        map<int, int>::iterator itr;
        vector<int> res;
        for(itr=mp.begin(); itr!=mp.end(); itr++)
        {
            res.push_back(itr->second);
        }
        return res;
    }
    
    void helper(Node* root, int col, map<int, int> &mp)
    {
        if(root==NULL)
        {
            return;
        }
        if(mp.find(col)==mp.end())
        {
            mp[col] = root->data;
        }
        else
        {
            mp[col] += root->data;
        }
        helper(root->left, col-1, mp);
        helper(root->right, col+1, mp);
    }
};
