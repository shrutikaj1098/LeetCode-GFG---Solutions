//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int dp[1000][1000];
    int rec(string &A,string &B,  int i,int j)
    {
        if(i==A.size() || j==B.size()) return 0;
        if(dp[i][j]!=-1)
      {
          return dp[i][j];
      }
        int ans=0;
        if(A[i]==B[j])
        {
            ans= 1+rec(A,B,i+1,j+1);
        }
        else ans=max(rec(A,B,i+1,j),rec(A,B,i,j+1));
        return dp[i][j]= ans;
    }
    int longestPalinSubseq(string s) {
        //code here
        string t=s;
        
        reverse(s.begin(),s.end());
        // cout<<B;
        memset(dp,-1,sizeof(dp));
        return rec(s,t,0,0);
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