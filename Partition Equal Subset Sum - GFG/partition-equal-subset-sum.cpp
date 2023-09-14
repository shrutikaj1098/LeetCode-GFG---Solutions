//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int rec(int N, int arr[], int target, int idx,vector<vector<int>>&dp)
    {
        if(target==0) return 1;
        if(target <0) return 0;
        if(idx>=N) return 0;
        if(dp[target][idx]!=-1) return dp[target][idx];
        int nt= rec(N,arr,target,idx+1,dp);
        int t= rec(N,arr,target-arr[idx],idx+1,dp);
        return dp[target][idx]=nt+t;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        
        if(sum%2!=0) return 0;
        int target=sum/2;
        vector<vector<int>>dp(target+1,vector<int>(N+1,-1));
        return rec(N,arr,target,0,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends