//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
             priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    int n=heights.size();
    int m=heights[0].size();
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    dist[0][0]=0;
    q.push({0,{0,0}});   
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    // vector<vector<int>>vis(n,vector<int>(m,0));
    // vis[0][0]=1;
    while(!q.empty())
    {
        int currheight=q.top().first;
        int r=q.top().second.first;
        int c=q.top().second.second;
        q.pop();
        if(r==n-1 && c==m-1) return dist[r][c];
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr<n && nc<m && nr>=0 && nc>=0)
            {
                
                    int neweffort=max(currheight,abs(heights[r][c]-heights[nr][nc]));
                    if(neweffort<dist[nr][nc])
                    {
                        dist[nr][nc]=neweffort;
                        q.push({neweffort,{nr,nc}});
                        
                    }
                    
                
            }
        }
    }
    return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends