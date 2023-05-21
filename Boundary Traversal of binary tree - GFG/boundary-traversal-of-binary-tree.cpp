//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
bool isleaf(Node*root)
{
    if(!root->right && !root->left)
    {
        return true;
    }
    return false;
}
    void solvel(Node* root, vector<int>&v,int level)
{
    Node*curr=root->left;
        while(curr)
        {
            if(!isleaf(curr)) v.push_back(curr->data);
            if(curr->left)curr=curr->left;
            else curr=curr->right;
        }
        
    
}
    void solver(Node* root, int level,vector<int>&v)
    {
        Node*curr=root->right;
        vector<int>r;
        while(curr)
        {
            if(!isleaf(curr)) r.push_back(curr->data);
            if(curr->right)curr=curr->right;
            else curr=curr->left;
        }
        reverse(r.begin(),r.end());
        for(int i=0;i<r.size();i++)
        {
            v.push_back(r[i]);
        }
        // if(!root) return;
        // if(r.size()==level &&!isleaf(root))
        // {
           
        //     r.push_back(root->data);
            
        // }
        // solver(root->right,level+1,r);
        // solver(root->left,level+1,r);
       
    }
    void solveleaf(Node* root,vector<int>&v)
    {
        if(!root)return;
        if(!root->left && !root->right)
        {
            v.push_back(root->data);
            return;
        }
        
        if(root->left)solveleaf(root->left,v);
        if(root->right)solveleaf(root->right,v);
    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>v;
   int level=0;
   if(!root) return v;
  if(!isleaf(root))v.push_back(root->data);
  solvel(root,v,level);
  solveleaf(root,v);
  
  solver(root,0,v);
    
   return v;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends