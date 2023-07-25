//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long func(int ind,int buy,vector<long long>&prices,vector<vector<long long>> &dp,int n,int fee){
        if(ind>=n){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            return dp[ind][buy]= max(-prices[ind]+func(ind+1,0,prices,dp,n,fee),
             func(ind+1,1,prices,dp,n,fee));
        }
        else{
            return dp[ind][buy]= max(prices[ind]-fee+func(ind+1,1,prices,dp,n,fee),func(ind+1,0,prices,dp,n,fee));
        }
    }
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
         vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return func(0,1,prices,dp,n,fee);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends