class Solution {
public:
    void bfs(int n,int m,int row, int col,vector<vector<int>>& vis, vector<vector<char>>& grid)
    {
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            
            q.pop();
            for(int nr=-1;nr<=1;nr++)
            {
                for(int nc=-1;nc<=1;nc++)
                {
                    int newr=r+nr;
                    int newc=c+nc;
                    if(abs(nr-nc)==1 && newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]=='1' && !vis[newr][newc])
                    {
                        vis[newr][newc]=1;
                        q.push({newr,newc});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(!vis[row][col] && grid[row][col]=='1')
                {
                    cnt++;
                    // vis[row][col]=1;
                    bfs(n,m,row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};