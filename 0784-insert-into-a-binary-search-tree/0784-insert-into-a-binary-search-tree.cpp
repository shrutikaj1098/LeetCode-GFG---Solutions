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
    TreeNode* insertIntoBST(TreeNode* root, int x) {
        if(!root) return new TreeNode(x);
        TreeNode* cur=root;
        while(true)
        {
            if(cur->val > x)
            {
                if(cur->left) cur=cur->left;
                else
                {
                    cur->left=new TreeNode(x);
                    break;
                }
            }
            else
            {
                if(cur->right) cur=cur->right;
                else
                {
                    cur->right=new TreeNode(x);
                    break;
                }   
            }
        }
        return root;
    }
};