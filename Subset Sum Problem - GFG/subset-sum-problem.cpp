//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool rec(vector<int>arr, int sum, int ind,vector<vector<int>>&dp)
    {
        if(sum==0) return 1;
        if(ind==0) return arr[0]==sum;
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        bool np= rec(arr,sum,ind-1,dp);
        bool p=false;
        if(arr[ind]<=sum)
        {
            p=rec(arr,sum-arr[ind],ind-1,dp);
        }
        return dp[ind][sum]=p|np;
        
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return rec(arr, sum, n-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends