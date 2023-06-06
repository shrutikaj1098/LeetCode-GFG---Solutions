class Solution {
public:
    int recsolve(int n)
    {
        if(n==0 || n==1)
        {
            return n;
        }
        int ans=fib(n-1)+fib(n-2);
        return ans;
    }
    int topdown(int n,vector<int>&dp)
    {
        if(n==0 || n==1) return n;
        if(dp[n]!=-1) return dp[n];
        dp[n]=topdown(n-1,dp)+topdown(n-2,dp);
        return dp[n];
    }
    int fib(int n) {
        // return recsolve(n);
        //topdown approach:
        vector<int>dp(n+1,-1);
        return topdown(n,dp);
    }
};