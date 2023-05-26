/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr ) return root;  
           
        
       int curr=root->val;
        if(curr<p->val && curr<q->val)
        {   cout<<root->val<<"R"<<endl;
           return lowestCommonAncestor(root->right,p,q);
        }
         if(curr>p->val && curr>q->val){cout<<root->val<<"L"<<endl; 
                return lowestCommonAncestor(root->left,p,q);}
        
        return root;
    
    }
};