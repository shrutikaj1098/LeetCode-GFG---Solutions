class Solution {
public:

    int rec(vector<vector<int>>& triangle, int i,int  j, int n,vector<vector<int>>&dp)
    {
        if(i==n-1) return triangle[n-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int s= triangle[i][j]+rec(triangle,i+1,j,n,dp);
        int p=triangle[i][j]+rec(triangle, i+1,j+1,n,dp);
        return dp[i][j]=min(s,p);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),-1));
        return rec(triangle,0,0, triangle.size(),dp);
    }
};