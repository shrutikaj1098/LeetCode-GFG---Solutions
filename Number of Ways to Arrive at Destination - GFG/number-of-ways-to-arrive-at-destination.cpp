//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        vector<pair<int,int>>adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>dist(n,1e15);
        dist[0]=0;
        q.push({0,0});
        vector<int>ways(n,0);
        ways[0]=1;
        while(!q.empty())
        {
            auto temp=q.top();
            q.pop();
            int node=temp.second;
            long long time=temp.first;
            for(auto it:adj[node])
            {
                int adjn=it.first;
                long long t=it.second;
                if(t+time<dist[adjn])
                {
                    dist[adjn]=t+time;
                    ways[adjn]=ways[node];
                    q.push({t+time,adjn});
                }
                else if(t+time==dist[adjn])
                {
                    ways[adjn]=(ways[adjn]+ways[node])%((int)1e9+7);
                }
            }
        }
        return ways[n-1]%((int)1e9+7);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends