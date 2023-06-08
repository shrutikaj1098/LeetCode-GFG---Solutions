class Solution {
public:
    int solveRecursion(vector<int> nums, int i)
    {
        if(i>nums.size()-1)
        {            
            return 0;
        }
        int rob1=nums[i]+solveRecursion(nums,i+2);
        int rob2=0+solveRecursion(nums,i+1);
        return max(rob1,rob2);
        
       
    }
    int solvememo(vector<int>& nums, int n,vector<int>&dp)
    {
        if(n<0) return 0;
        if(n==0) return nums[0];
        if(dp[n]!=-1) return dp[n];
            

        int rob1=nums[n]+solvememo(nums,n-2,dp);
        int rob2=solvememo(nums,n-1,dp);
        dp[n]= max(rob1,rob2);
        return dp[n];


    }
    int rob(vector<int>& nums) {
        // return solve(nums,0);
        int n=nums.size()-1;
        vector<int>dp(n+1,-1);
        return solvememo(nums,n,dp);
    }
};