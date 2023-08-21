//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// # define long long int ll;
class Solution {
  public:
    int mod=1e9+7;
    int dp[10000];
    long long int solve( int h)
    {
        if(h<=1) return 1;
        if(dp[h]!=-1) return dp[h];
        long long int leftsmall=(solve(h-1)%mod*solve(h-2)%mod)%mod;
        long long int equal=(solve(h-1)%mod* solve(h-1)%mod)%mod;
        
        return dp[h]=(leftsmall+leftsmall+equal)%mod;
    }
    long long int countBT(int h) { 
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(h);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends