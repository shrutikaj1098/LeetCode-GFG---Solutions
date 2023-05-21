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
    // void solve(TreeNode* root, string &s)
    // {
    //     if(!root) return ;
    //     s+=to_string(root->val);
    //     solve(root->left,s);
    //     solve(root->right,s);

    // }
    bool solve2(TreeNode* p, TreeNode* q)
    {
        if(!p && !q) return 1;
        if(!p && q) return 0;
        if(p && !q) return 0;
        if(p->val!=q->val) return 0;
        return p->val ==q->val&&solve2(p->left, q->left) && solve2(p->right,q->right);
    }
    bool solve(TreeNode* root, TreeNode* subRoot)
    {
        if(!root) return false ;
        static int count=0;
        // if(count==1) return true;
        // bool lh =;
        // bool rh=;
        if(solve2(root,subRoot))
        {            
            // count++;
            return true;
            
        }
        return solve(root->left,subRoot) ||solve(root->right,subRoot);
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // string s1="";
        // string s2="";
        // solve(root,s1);
        // solve(subRoot,s2);
        // int i=0,j=0;
        // // return s1.find(s2)!=string::npos;
        // cout<<s1<<endl<<s2;
        // if(s1.find(s2)!=string::npos)
        // {
        //     i=s1.find(s2);
        // }
        // else
        // {
        //     return false;
        // }
        // while(i<s1.length())
        // {
        //     if(s1[i]!=s2[j])
        //     {
        //         return false;
        //     }
        //     i++,j++;
        // }
        // return true;

        if(!root && !subRoot) return true;
        if(!root && subRoot)return false;
        if(root && !subRoot) return false;
        return solve(root,subRoot);
    }
};