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
    void solve(TreeNode* root, int &sum, int ind)
    {
        if(!root) return ;
        if(!root->left && !root->right)
        {
            ind=ind*10+root->val;
            sum+=ind;
            return;
        }
        ind=ind*10+root->val;
        if(root->left)solve(root->left,sum,ind);
        if(root->right)solve(root->right,sum,ind);
    }
    int sumNumbers(TreeNode* root) {
        if(root==nullptr) return 0;
        int sum=0;
        int ind=0;
        solve(root,sum,ind);
        return sum;


    }
};