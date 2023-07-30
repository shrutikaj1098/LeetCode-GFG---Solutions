class Solution {
public:
vector<vector<int>>dp;
    int solve(string s, int i,int k)
    {
        if(i==k)return 1;
        if(i>k)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int ans = 1+solve(s,i+1,k);
        for(int j=i+1;j<s.length();j++)
        {
            if(s[i]==s[j])
            {
                ans = min(ans,solve(s,i+1,j-1)+solve(s,j,k));
                // break;
            }
        }

        return dp[i][k]=ans;
    }
    int strangePrinter(string s) {
        int n = s.length();
        dp=vector<vector<int>>(n,vector<int>(n,-1));
        return solve(s,0,n-1);
    }
};