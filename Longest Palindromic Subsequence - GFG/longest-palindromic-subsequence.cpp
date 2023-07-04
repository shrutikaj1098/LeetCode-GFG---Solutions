//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int rec(int i, int j, string &s1, string &s2,vector<vector<int>>&dp)
    {
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if( s1[i-1]==s2[j-1]) return 1+ rec(i-1,j-1,s1,s2,dp);
        
        return dp[i][j]=max(rec(i-1,j,s1,s2,dp) , rec(i,j-1,s1,s2,dp));
        
    }
    int longestPalinSubseq(string A) {
        //code here
        
        string s1=A;
        string s2=A;
        reverse(s2.begin(),s2.end());
        int x=A.length(),y=A.length();
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        return rec(x,y,s1,s2,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends