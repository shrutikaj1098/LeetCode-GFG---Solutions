//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
  
    int rec(int arr[], int ind,vector<int>&dp)
    {
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int nt= rec(arr, ind-1,dp);
        int take=arr[ind]+rec(arr,ind-2,dp);
        return dp[ind]=max(nt,take);
        
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
       vector<int>dp(n,-1);
        return rec(arr,n-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends