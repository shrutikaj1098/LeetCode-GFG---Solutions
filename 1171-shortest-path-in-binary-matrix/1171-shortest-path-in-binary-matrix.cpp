class Solution {
public:
    bool isSafe(int i, int j,int row,int col, vector<vector<int>>& grid,vector<vector<bool>>&visited)
    {
        if((i>=0 && i<row) &&(j>=0 && j<col) && !visited[i][j] && grid[i][j]==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void solve(vector<vector<int>>& grid,int row,int col, int i,int j,vector<vector<bool>>&visited ,vector<string>&path, string output)
    {
        if(i>row && j>col)
        {
            path.push_back(output);
            return;
        }

        //Down
        if(isSafe(i+1,j+1,row,col,grid,visited))
        {
            visited[i+1][j+1]=true;
            solve(grid,row,col,i+1,j+1,visited,path,output+'D');
            visited[i+1][j+1]=false;
        }
        //Right
        if(isSafe(i,j+1,row,col,grid,visited))
        {
            visited[i][j+1]=true;
            solve(grid,row,col,i,j+1,visited,path,output+'R');
            visited[i][j+1]=false;
        }
        //Left
        if(isSafe(i,j-1,row,col,grid,visited))
        {
            visited[i][j-1]=true;
            solve(grid,row,col,i,j-1,visited,path,output+'L');
            visited[i][j-1]=false;
        }
        //Up
        if(isSafe(i-1,j,row,col,grid,visited))
        {
            visited[i-1][j]=true;
            solve(grid,row,col,i-1,j,visited,path,output+'U');
            visited[i-1][j]=false;
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
    
    //  int row=grid.size();
    //  int col=grid[0].size() ;
    //   vector<vector<bool>>visited(row,vector<bool>(col,false));
    //  vector<string>path;
    //  string output="";
    //  solve(grid,row,col,0,0,visited,path,output);
    //  int mini=INT_MAX;
    //  for(auto i:path)
    //  {
    //      cout<<i;
    //      if(mini>i.size())
    //      {
    //          mini=i.size();
    //      }
    //  }
    //  return mini;
    int n=g.size();
        if(g[0][0] || g[n-1][n-1])return -1;
        g[0][0]=1;
        queue<pair<int,int>>q;
        q.push({0,0});
        int t=0;
        while(q.size()){
            int k=q.size();
            t++;
            while(k--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==n-1 && y==n-1)return t;
                int dx[8]={1,-1,0,0,1,1,-1,-1};
                int dy[8]={0,0,1,-1,1,-1,1,-1};
                for(int i=0;i<8;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<n && g[nx][ny]==0){
                        g[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};