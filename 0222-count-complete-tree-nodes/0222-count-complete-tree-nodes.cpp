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
    void solve(TreeNode* root, int &total)
    {
        if(!root) return;
        total++;
        if(root->left)solve(root->left,total);
        if(root->right)solve(root->right,total);
    }
    int countNodes(TreeNode* root) {
        // int total=0;
        // solve(root,total);
        // return total;
         if(!root)
            return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};