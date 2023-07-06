class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node]=1;
        for(auto i:adj[node]){
            if(vis[i]==0)
                dfs(i,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& graph) {
        int v = graph.size();
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