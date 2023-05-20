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
    string tree2str(TreeNode* root) {
        if(!root) return "";
        stack<TreeNode*>st;
        st.push(root);
        string s="";
        set<TreeNode*>visited;
        while(!st.empty())
        {
            root=st.top();
            if(visited.find(root)!=visited.end())
            {
                st.pop();
                s+=")";
            }
            else
            {
                visited.insert(root);
                s+="("+to_string(root->val);
                if(!root->left && root->right)
                {
                    s+="()";
                }
                if(root->right)
                {
                    st.push(root->right);
                }
                if(root->left)
                {
                    st.push(root->left);
                }
            }
        }
        return s.substr(1,s.length()-2);
    }
};