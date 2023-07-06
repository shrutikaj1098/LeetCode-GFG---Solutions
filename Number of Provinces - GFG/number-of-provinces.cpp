//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node]=1;
        for(auto i:adj[node]){
            if(vis[i]==0)
                dfs(i,adj,vis);
        }
    }
    int numProvinces(vector<vector<int>> graph, int v) {
        // code here
        
        vector<int> adj[v];
        // create a adjacency list

        for(int i = 0; i<v;i++){
            for(int j = 0 ; j<v; j++){
                if(graph[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(v,0);
        int c = 0;
        for(int i = 0; i<v; i++){
            if(vis[i]==0){
                c++;
                dfs(i,adj,vis);
            }
        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends