//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    struct node
	    {
	        int data;
	        node* left;
	        node* right;
	        
	        node(int val)
	        {
	            data=val;
	            left=nullptr;
	            right=nullptr;
	        }
	    };
	    struct comp
	    {
	       bool operator()(node* a, node*b)
	      {
	          return a->data > b->data;
	      }
	    };
	    void preorder(node* root,vector<string>&s, string op)
	    {
	        if(!root) return;
	        if(!root->left && !root->right)
	        {
	            s.push_back(op);
	        }
	        preorder(root->left,s,op+"0");
	        preorder(root->right,s,op+"1");
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<node*, vector<node*>, comp>pq;
		    for(int i=0;i<N;i++)
		    {
		        node* temp=new node(f[i]);
		        pq.push(temp);
		    }
		    while(pq.size()!=1)
		    {
		        node* left=pq.top();
		        pq.pop();
		        node* right=pq.top();
		        pq.pop();
		        node* parent=new node(left->data+right->data);
		        parent->left=left;
		        parent->right=right;
		        pq.push(parent);
		    }
		    node* root=pq.top();
		    vector<string>s;
		    preorder(root,s,"");
		    return s;
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends