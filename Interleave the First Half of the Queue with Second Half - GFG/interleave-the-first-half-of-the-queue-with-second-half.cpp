//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int>qq;
        int n=q.size()/2;
        while(n>0)
        {
            qq.push(q.front());
            q.pop();
            n--;
        }
        vector<int>v;
        // cout<<qq.size()<<q.size();
        while(!q.empty() || !qq.empty())
        {
            if(qq.front()){v.push_back(qq.front());qq.pop();}
            if(q.front()){v.push_back(q.front());q.pop();}
            
            
            
        }
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends