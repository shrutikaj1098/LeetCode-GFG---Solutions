//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        vector<vector<int>>vis(N,vector<int>(M,0));
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        vis[0][0]=1;
        int dr[4]={0,0,-1,1};
        int dc[4]={1,-1,0,0};
        if(A[0][0]==0) return 0;
        while(!q.empty())
        {
            auto node=q.front();
            int step=node.first;
            int r=node.second.first;
            int c=node.second.second;
            q.pop();
            if(r==X && c==Y) return step;
            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<N && nc<M && !vis[nr][nc] && A[nr][nc]==1)
                {
                    q.push({step+1,{nr,nc}});
                    vis[nr][nc]=1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends