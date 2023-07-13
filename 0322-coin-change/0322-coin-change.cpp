class Solution {
public:
int mini=INT_MAX;
    int rec(vector<int>& coins, int amount,int ind,vector<vector<int>>&dp)
    {
       if(ind< 0 ||amount<0) return INT_MAX-1;
       if(amount==0) return 0;
       if(dp[ind][amount]!=-1) return dp[ind][amount];
       int nt=rec(coins,amount,ind-1,dp);
       int t=INT_MAX;
       if(amount>=coins[ind])
       {
           t=1+rec(coins,amount-coins[ind],ind,dp);
       }
       return dp[ind][amount]=min(t,nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=rec(coins,amount,n-1,dp);
        if(ans==INT_MAX-1) return -1;
        else return ans;
        }
};