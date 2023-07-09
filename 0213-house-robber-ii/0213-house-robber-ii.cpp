class Solution {
public:
    int rec(vector<int>& nums,int ind,vector<int>&dp)
    {
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int nt=rec(nums,ind-1,dp);
        int t=nums[ind]+rec(nums,ind-2,dp);

        return dp[ind]=max(t,nt);

        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (nums.size() == 1)
        {
            return nums[0];
        }
        vector<int>h1,h2;
        for(int i=0;i<n;i++)
        {
            if(i!=n-1)
            {
                h1.push_back(nums[i]);
            }
            if(i!=0)
            {
                h2.push_back(nums[i]);
            }
        }
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int ans1=rec(h1,h1.size()-1,dp1);
        int ans2=rec(h2,h2.size()-1,dp2);
        
        return max(ans1,ans2);
    }
};