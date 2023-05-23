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
     TreeNode* solve(vector<int>& postorder,int prestart, int preend, vector<int>& inorder,int instart,int inend,map<int,int>&inmap)
    {
        if(prestart>preend || instart>inend) return nullptr;
        TreeNode* root= new TreeNode(postorder[preend]);
        int inroot=inmap[root->val];
        int numsleft=inroot-instart;
        root->left=solve(postorder, prestart,prestart+numsleft-1,inorder,instart,inroot-1,inmap);
        root->right= solve(postorder, prestart+numsleft,preend-1, inorder, inroot+1,inend,inmap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>inmap;
        for(int i=0;i<inorder.size();i++)
        {
            inmap[inorder[i]]=i;
        }
        TreeNode* root=solve(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inmap);
        return root;
    }
};