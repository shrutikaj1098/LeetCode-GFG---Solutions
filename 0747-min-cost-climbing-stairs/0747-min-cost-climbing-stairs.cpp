class Solution {
public:
    int rec(vector<int>& cost, int ind,vector<int>&dp)
    {
        if(ind==0 || ind==1) return cost[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=min(cost[ind]+rec(cost,ind-1,dp),cost[ind]+rec(cost,ind-2,dp));
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
        return min(rec(cost,cost.size()-1,dp),rec(cost,cost.size()-2,dp));
    }
};