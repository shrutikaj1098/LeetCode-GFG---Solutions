class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int col, int color[], int node)
    {
        color[node]=col;
        for(auto it:graph[node])
        {
            if(color[it]==-1 )
            {
                if(dfs(graph, !col,color, it)==false) return false;
            }
            else if(color[it]==color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int color[n];
        for(int i=0;i<n;i++)color[i]=-1;
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(graph,0, color,i)==false) return false;
            }
        }
        return true;
    }
};