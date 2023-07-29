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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode *,pair<int,int>>>q;
    if(!root) return {};
    map<int,map<int,multiset<int>>>mp;
    q.push({root,{0,0}});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        auto node=it.first;
        int v=it.second.first;
        int l=it.second.second;
        mp[v][l].insert(node->val);
        if(node->left) q.push({node->left,{v-1,l+1}});
        if(node->right) q.push({node->right,{v+1,l+1}});
        
    }
    vector<vector<int>>ans;
    for(auto it:mp)
    {
        vector<int>col;
        for(auto k:it.second)
        {
            // cout<<k.first;
            
             col.insert(col.end(),k.second.begin(),k.second.end());
        }
        ans.push_back(col);
    }
    return ans;
    }
};