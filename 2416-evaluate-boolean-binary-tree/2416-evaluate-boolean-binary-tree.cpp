/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool solve(TreeNode* root, bool &value)
    {
        if(!root->left &&!root->right) 
        {
            if(root->val==0) return false;
            else if(root->val==1) return true;
        }
        bool left=solve(root->left,value);
        bool right=solve(root->right,value);
        if(root->val==2)
        {
            return left||right;
        }
        else if(root->val==3)
        {
            return left&&right;
        }
        return false;
        



    }
    bool evaluateTree(TreeNode* root) {
        bool value=false;
        return solve(root,value);
    }
};
