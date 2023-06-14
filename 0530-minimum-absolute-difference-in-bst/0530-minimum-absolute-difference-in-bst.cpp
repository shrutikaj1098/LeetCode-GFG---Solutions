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
    void solve(TreeNode* root, vector<int>&v)
    {
        if(!root) return;
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>v;
        solve(root,v);
        int mini=INT_MAX;
        for(int i=0;i<v.size()-1;i++)
        {
            mini=min(mini,v[i+1]-v[i]);
        }
        return mini;
    }
};