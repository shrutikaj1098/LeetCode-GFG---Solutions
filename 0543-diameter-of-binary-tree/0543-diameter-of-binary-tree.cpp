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
    //  int maxDepth(TreeNode* root) {
    //     if(root==nullptr)
    //     {
    //         return 0;
    //     }
    //     int lh=maxDepth(root->left);
    //     int rt=maxDepth(root->right);
    //     return 1+max(lh,rt);
    // }
    int solve(TreeNode* root, int & diameter)
    {
        if(!root) return 0;
        int lh= solve(root->left,diameter);
        int rh= solve(root->right,diameter);
        diameter=max(diameter, lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // if(root==nullptr)return 0;
        // int op1=diameterOfBinaryTree(root->left);
        // int op2=diameterOfBinaryTree(root->right);
        // int op3=maxDepth(root->right)+maxDepth(root->left);
        // int ans=max(op1,max(op2,op3));
        // return ans;

        int diameter=0;
        if(!root) return 0;
        solve(root,diameter);
        return diameter;
    }
};