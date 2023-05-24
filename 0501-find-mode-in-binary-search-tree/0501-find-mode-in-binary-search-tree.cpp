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
 bool cmp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.second>b.second;
    }
class Solution {
    
public:
    void solve(TreeNode* root,map<int,int>&mp)
    {
        if(!root) return ;
        solve(root->left,mp);
        mp[root->val]++;
        solve(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int>mp;
        vector<pair<int,int>>v;
        vector<int>ans;
        solve(root,mp);
        for(auto i:mp)
        {
            v.push_back(i);
        }
        sort(v.begin(),v.end(),cmp);
        map<int,vector<int>>m;
        for(auto i:v)
        {
            m[i.second].push_back(i.first);
        }
        int count=m.size();
        int a=0;
        for(auto i:m)
        {
            if(a==count-1)
            {
                int n=i.second.size();
                for(int j=0;j<n;j++)
                {
                    ans.push_back(i.second[j]);
                }
            }
            a++;
            
        }
        return ans;;
    }
};