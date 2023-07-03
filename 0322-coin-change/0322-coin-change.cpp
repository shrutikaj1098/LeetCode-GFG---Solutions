class Solution {
public:
    int solve(vector<int>& coins, int amount,int ind,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(amount%coins[ind]==0) return amount/coins[ind];
            return 1e9;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int np=0+solve(coins,amount,ind-1,dp);
        int p=1e9;
        if(coins[ind]<=amount)
        {
            p=1+solve(coins,amount-coins[ind],ind,dp);
        }
        return dp[ind][amount]=min(p,np);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=solve(coins, amount ,n-1,dp);
        if(ans>=1e9) return -1;
        return ans;
        }
};