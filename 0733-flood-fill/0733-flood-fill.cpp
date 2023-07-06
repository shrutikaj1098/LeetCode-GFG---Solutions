
class Solution {
public:
    
    void dfs(int r, int c,vector<vector<int>>& ans,vector<vector<int>>& image, int inicolor,int color,int delr[], int delc[])
    {
        ans[r][c]=color;
        int n=ans.size();
        int m=ans[0].size();
        for(int i=0;i<4;i++)
        {
            int nr=r+delr[i];
            int nc=c+delc[i];
            if(nr>=0 &&nr<n && nc>=0 && nc<m && image[nr][nc]==inicolor && ans[nr][nc]!=color)
            {
                dfs(nr,nc,ans,image,inicolor,color,delr,delc);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        vector<vector<int>>ans=image;
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        dfs(sr,sc,ans,image,inicolor,color,delr,delc);
        return ans;
    }
};