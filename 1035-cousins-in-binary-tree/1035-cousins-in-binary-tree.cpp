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
   int find_HeightParent(TreeNode *curr,int &parent,int value,int height)
    {
        if(!curr)
            return 0;
        if(curr->val==value)
            return height;
        
        parent = curr->val;
        int left = find_HeightParent(curr->left,parent,value,height+1);
        if(left)
            return left;
        parent = curr->val;
        int right = find_HeightParent(curr->right,parent,value,height+1);
        return right;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x || root->val==y)
            return false;
            
        int parent=-1;
        int xHeight = find_HeightParent(root,parent,x,0);
        
        int yParent=-1;
        int yHeight = find_HeightParent(root,yParent,y,0);
        
        if(parent!=yParent && xHeight==yHeight)
            return true;        
        return false;
    }
};