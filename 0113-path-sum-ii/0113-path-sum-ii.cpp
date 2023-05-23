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
    void solve(TreeNode* root, int &targetSum,vector<vector<int>>&v,int sum,vector<int>ind)
    {
        if(!root)return;
        
        
        if(!root->left && !root->right)
        {
            sum+=root->val;
            ind.push_back(root->val);
            if(sum==targetSum)
            {
                v.push_back(ind);
                return;
            }
        }
        ind.push_back(root->val);
        if(root->left)solve(root->left,targetSum,v,sum+root->val,ind);
        if(root->right)solve(root->right,targetSum,v,sum+root->val,ind);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>v;
        int sum=0;
        vector<int>ind;
        solve(root,targetSum,v,sum,ind);
        return v;
    }
};