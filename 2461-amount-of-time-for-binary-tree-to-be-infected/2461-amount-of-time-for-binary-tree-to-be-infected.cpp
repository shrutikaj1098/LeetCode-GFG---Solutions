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
    TreeNode*target=nullptr;
void make_parents(unordered_map<TreeNode*,TreeNode*>&parent, TreeNode* root )
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            TreeNode* node=q.front();
            q.pop();
            if(node->left)
            {
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right)
            {
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
}
void gettarget(TreeNode* root, int start)
{
    if(!root) return;
    if(root->val==start)
    {
        target=root;
        return;
    }
    gettarget(root->left,start);
    gettarget(root->right,start);
}
    int amountOfTime(TreeNode* root, int start) {
         unordered_map<TreeNode*,TreeNode*>parent;
    make_parents(parent,root);
    int time=0;
    gettarget(root,start);
    queue<TreeNode*>q;
    unordered_map<TreeNode*,bool>visited;
    q.push(target);
    visited[target]=1;
    while(!q.empty())
    {
        int n=q.size();
        time++;
        for(int i=0;i<n;i++)
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left && !visited[curr->left])
            {
                q.push(curr->left);
                visited[curr->left]=1;
            }
            if(curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                visited[curr->right]=1;
            }
            if(parent[curr] && !visited[parent[curr]])
            {
                q.push(parent[curr]);
                visited[parent[curr]]=1;
            }
        }
    }
    return time-1;
    }
};