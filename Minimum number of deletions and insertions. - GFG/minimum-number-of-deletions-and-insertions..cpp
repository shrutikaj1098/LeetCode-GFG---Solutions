//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int rec(int i,int j, string str1, string str2,vector<vector<int>>&dp)
	{
	    if(i==0 || j==0) return 0;
	    if(dp[i][j]!=-1) return dp[i][j];
	    if(str1[i-1]==str2[j-1]) return 1+rec(i-1,j-1,str1,str2,dp);
	    return dp[i][j]=max(rec(i-1,j,str1,str2,dp),rec(i,j-1,str1,str2,dp));
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n=str1.length(),m=str2.length();
	    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	    return n+m-2*rec(n,m,str1,str2,dp);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends