class Solution {
public:
bool dfs(int node,vector<vector<int>>& adj,vector<int>&vis, vector<int>&pathvis, vector<int>&check)
    {
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,pathvis,check)==true) 
                {
                    check[node]=0;
                    return true;
                }
            }
            else if(vis[it] && pathvis[it])
            {
                    check[node]=0;
                    return true;
            }
        }
        check[node]=1;
        pathvis[node]=0;
        // vis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
         int V=adj.size();
        vector<int>vis(V,0);
        // int pathvis[V]={-1};
        vector<int>pathvis(V,-1);
        vector<int>check(V,0);
        // int check[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,pathvis,check) ;
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
};