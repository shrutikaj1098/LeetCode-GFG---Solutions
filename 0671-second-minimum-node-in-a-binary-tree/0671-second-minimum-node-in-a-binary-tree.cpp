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
    void solve(TreeNode* root, set<int>&s)
    {
        if(!root) return;
        s.insert(root->val);
        solve(root->left,s);
        solve(root->right,s);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int>s;
        solve(root,s);
        auto it=s.begin();
        cout<<s.size();
        if(s.size()>1){
        advance(it,1);}
        
        return s.size()>1?*it:-1;
    }
};