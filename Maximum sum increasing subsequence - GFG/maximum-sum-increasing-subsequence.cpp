//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int rec(int n , int cur, int prev, int a[],vector<vector<int>>&dp)
    {
        if(cur>=n) return 0;
        if(dp[cur][prev+1]!=-1) return dp[cur][prev+1];
        int len=0+rec(n,cur+1,prev,a,dp);
        if(prev==-1 || a[cur]>a[prev])
        {
            len=max(len,a[cur]+rec(n,cur+1,cur,a,dp));
        }
        return dp[cur][prev+1]=len;
    }
	int maxSumIS(int a[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	    return rec(n,0,-1,a,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends