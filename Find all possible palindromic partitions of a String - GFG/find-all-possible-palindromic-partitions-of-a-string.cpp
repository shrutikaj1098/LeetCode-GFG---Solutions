//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    bool ispalindrome(string s)
    {
        string t=s;
        reverse(s.begin(),s.end());
        return t==s;
    }
    void backtrack(string s,  vector<vector<string>>&ans, int idx, vector<string> op)
    {
        if(idx==s.size())
        {
            ans.push_back(op);
            return;
        }
        string temp="";
        for(int i=idx;i<s.size();i++)
        {
            temp+=s[i];
            if(ispalindrome(temp))
            {
                op.push_back(temp);
                backtrack(s,ans,i+1,op);
                op.pop_back();
            }
        }
        
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>>ans;
        vector<string>op;
        backtrack(S,ans,0,op);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends