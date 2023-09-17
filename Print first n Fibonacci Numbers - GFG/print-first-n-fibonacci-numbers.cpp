//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    int rec(int n, vector<long long>&vec,vector<int>&dp)
    {
        if(n==0 ||n==1) 
        {
            vec.push_back(n);
            
            return 1;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n]=rec(n-1,vec,dp)+rec(n-2,vec,dp);
    }
    vector<long long> printFibb(int n) 
    {
        //code here
        vector<long long>vec;
        vector<long long>dp(n,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp;
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
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends