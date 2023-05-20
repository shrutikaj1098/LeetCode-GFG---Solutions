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
    int convertBTD(string ans)
    {
        int value=0;
        reverse(ans.begin(),ans.end());
        int k=0;
        for(int i=0;i<ans.size();i++)
        {
            value+= (int(ans[i])-48)*pow(2,k);
            k++;
        }
        // cout<<value<<"v"<<endl;
        return value;
    }
    void solve(TreeNode* root, int &ans,string st)
    {
        if(!root) return;
       
        st+=to_string(root->val);
        solve(root->left,ans,st);
        solve(root->right,ans,st);
         if(!root->left && !root->right)
        {
            ans+=convertBTD(st);
        }
        // cout<<st<<endl;
        // st.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
        string st="";
        solve(root,ans,st);
        return ans;
    }
};