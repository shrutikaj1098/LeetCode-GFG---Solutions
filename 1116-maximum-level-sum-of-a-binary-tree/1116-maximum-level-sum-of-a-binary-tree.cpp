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
 bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    return a.second>b.second;
}
class Solution {
public:

    int maxLevelSum(TreeNode* root) {
        vector<pair<int,int>>v;
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            int ans=0;
            level++;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                ans+=temp->val;
            }
            v.push_back({level,ans});
        }
        sort(v.begin(),v.end(),cmp);
        return v[0].first;
    }
};