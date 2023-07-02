class Solution {
public:
    int rec(vector<vector<int>>& grid, int i, int j,vector<vector<int>>&dp )
	{
	    if(i==0 && j==0) return grid[0][0];
	    if(i<0 || j<0) return 1e9;
	   // if(i==grid.size() || j==grid[0].size()) return INT_MAX;
	    if(dp[i][j]!=-1) return dp[i][j];
	    int up= grid[i][j]+rec(grid,i-1,j,dp);
	    int left=grid[i][j]+rec(grid,i,j-1,dp);
	   // int right=grid[i][j]+rec(grid,i,j+1);
	   // int down=grid[i][j]+rec(grid,i,j-1);
	    
	    return dp[i][j]=min(up,left);
	}
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return rec(grid,grid.size()-1,grid[0].size()-1,dp);
    }
};