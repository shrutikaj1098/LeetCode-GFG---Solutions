//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<string>ans;
    void rec(string s, int idx, string op)
    {
        if(idx==s.size())
        {
            ans.push_back(op);
            return;
        }
        rec(s,idx+1,op+' '+s[idx]);
        rec(s,idx+1,op+s[idx]);
        
    }
    vector<string> permutation(string S){
        // Code Here
        
        string op="";
        op+=S[0];
        rec(S,1,op);
        return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends