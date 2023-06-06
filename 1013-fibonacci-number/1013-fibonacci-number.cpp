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
    int bottomup(int n)
    {
        vector<int>dp(n+1,-1);
        dp[0]=0;
        if(n==0) return dp[0];
        dp[1]=1;
        if(n==1) return dp[1];
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int spaco(int n)
    {
        int prev2=0;
        if(n==0) return prev2;
        int prev1=1;
        if(n==1) return prev1;
        int curr;
        for(int i=2;i<=n;i++)
        {
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
    int fib(int n) {
        // return recsolve(n);
        //topdown approach: recursive memoisation
        // vector<int>dp(n+1,-1);
        // return topdown(n,dp);
        //bottom up approach : iterative tabular method
        // return bottomup( n);
        //Space optimization:
        return spaco(n);
    }
};