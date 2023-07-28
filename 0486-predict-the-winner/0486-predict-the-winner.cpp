class Solution {
public:
    int dp[100][100];
    int rec(int i, int j, vector<int>&nums)
    {
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int leftchoice= nums[i]-rec(i+1,j,nums);
        int rightchoice=nums[j]-rec(i,j-1,nums);

        return dp[i][j]=max(leftchoice,rightchoice);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,n-1,nums)>=0;
    }
};