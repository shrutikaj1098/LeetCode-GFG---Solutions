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
    bool check(vector<int>temp,int level)
    {
        if(temp.size()==1 && level%2==0)
        {
            if(temp[0]%2==0) return false;
        }
        else if(temp.size()==1 && level%2!=0)
        {
             if(temp[0]%2!=0) return false;
        }
        if(level%2==0)
        {
            for(int i=0;i<temp.size()-1;i++)
            {
                if(temp[i]%2==0||temp[i+1]%2==0) return false;
                if(temp[i]>=temp[i+1]) return false;
            }
        }
        else if(level%2!=0)
        {
            for(int i=0;i<temp.size()-1;i++)
            {
                if(temp[i]%2!=0 ||temp[i+1]%2!=0) return false;
                if(temp[i]<=temp[i+1] ) return false;
            }
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        
         if(!root) return false;
        
        queue<TreeNode*>q;
        q.push(root);
        int level=-1;
        while(!q.empty())
        {
            level++;
            vector<int>temp;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                temp.push_back(node->val);
            }
            bool flag=check(temp,level);
            cout<<flag;
            if(!flag) return false;
        }
        return true;
    }
};