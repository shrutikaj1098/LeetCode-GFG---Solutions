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
    void solve(TreeNode* root, int &count,int curr)
    {
        if(!root) return ;
       if(root->val>=curr)
       {
           curr=root->val;
           count++;
       }
        solve(root->left, count,curr);
        solve(root->right, count,curr);
        
       
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        if(!root) return 0;
        
        solve(root,count,root->val);
        return count;
    }
};