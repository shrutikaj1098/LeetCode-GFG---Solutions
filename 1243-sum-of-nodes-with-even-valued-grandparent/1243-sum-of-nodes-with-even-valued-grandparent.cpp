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
    int sum=0;
    void solve(TreeNode* root)
    {
        if(!root) return;
        if(root->val%2==0)
        {
            getchild(root->left);
            getchild(root->right);
        }
        solve(root->left);
        solve(root->right);
    }
    void getchild(TreeNode* root)
    {
        if(!root) return;
        if(root->left)
        {
            sum+=root->left->val;
        }
        if(root->right)
        {
            sum+=root->right->val;
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        solve(root);
        return sum;
    }
};