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
    int num=0;
    int count=0;
    void solve(TreeNode* root)
    {
        if(!root) return;
        
        if(getsum(root)/count==root->val) num++;
        count=0;
        if(root->left)
        {
            
            solve(root->left);
        }
        
        if(root->right)
        {
            
            solve(root->right);
        }
        // cout<<root->val<<value<<count<<endl;        

    }
    int getsum(TreeNode* root)
    {
        if(!root) return 0;
        count++;
        return root->val+getsum(root->left)+getsum(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return num;
    }
};