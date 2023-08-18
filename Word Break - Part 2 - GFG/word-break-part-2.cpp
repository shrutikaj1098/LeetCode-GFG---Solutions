//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void backtrack(int n, int index,string s, unordered_set<string>&st,vector<string>&ans, string op)
    {
        if(index==s.size())
        {
            ans.push_back(op.substr(1));
            return;
        }
        string temp="";
        for(int i=index;i<s.size();i++)
        {
            temp+=s[i];
            if(st.find(temp)!=st.end())
            {
                backtrack(n,i+1,s,st,ans,op+" "+temp);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        unordered_set<string>st;
        for(auto i:dict)
        {
            st.insert(i);
        }
        vector<string>ans;
        string op="";
        backtrack(n,0,s,st,ans,op);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends