//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int rec(int price[], int ind,int len[],int n,vector<vector<int>>&dp)
    {
        if(ind<0) return 0;
        if(n<0) return 0;
        if(dp[ind][n]!=-1) return dp[ind][n];
        int nt=rec(price,ind-1,len,n,dp);
        int t=0;
        if(len[ind]<=n)
        {
            t= price[ind]+rec(price, ind, len,n-len[ind],dp);
        }
        return dp[ind][n]=max(t,nt);
    }
    int cutRod(int price[], int n) {
        //code here
        int len[n];
        for(int i=0;i<n;i++)
        {
            len[i]=i+1;
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return rec(price, n-1,len,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends