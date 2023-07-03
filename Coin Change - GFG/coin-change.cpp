//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long solve(int coins[], int amount,int ind,vector<vector<long long>>&dp)
    {
        if(ind==0)
        {
            return amount%coins[ind]==0;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        long long np=0+solve(coins,amount,ind-1,dp);
        long long p=0;
        if(coins[ind]<=amount)
        {
            p=solve(coins,amount-coins[ind],ind,dp);
        }
        return dp[ind][amount]=p+np;
    }
    long long int count(int coins[], int n, int amount) {

        
        vector<vector<long long>>dp(n+1,vector<long long>(amount+1,-1));
        return solve(coins, amount ,n-1,dp);
        // if(ans>=1e9) return -1;
        // return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends