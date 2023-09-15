//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod=1e9+7;
    long long rec(int n, vector<int>&dp)
    {
        if(dp[n]!=-1) return dp[n];
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 4;
        
        return dp[n]=(rec(n-1,dp)%mod+rec(n-2,dp)%mod+rec(n-3,dp)%mod)%mod;
    }
    long long countWays(int n)
    {
        
        // your code here
        vector<int>dp(n+1,-1);
        return rec(n,dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends