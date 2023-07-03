class Solution {
public:
    bool rec(vector<int>&nums,int ind, int sum,vector<vector<int>>&dp)
    {
        if(sum==0) return 1;
        if(ind==0) return nums[0]==sum;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool np=rec(nums,ind-1,sum,dp);
        bool p=false;
        if(nums[ind]<=sum)
        {
            p=rec(nums,ind-1,sum-nums[ind],dp);
        }
        return dp[ind][sum]=p|np;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return rec(nums,n-1,sum/2,dp);
    }
};