//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
        // Code here 
        int inicolor=image[sr][sc];
        vector<vector<int>>ans=image;
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        dfs(sr,sc,ans,image,inicolor,color,delr,delc);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends