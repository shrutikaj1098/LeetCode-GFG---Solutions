class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& graph) {
        vector<int> adj[V];
        for(auto it:graph)
        {
            int f=it[1];
            int m=it[0];
            adj[f].push_back(m);
        }

        vector<int> indegree(V,0);
       for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        // reverse(topo.begin(),topo.end());
        if(topo.size()==V) return topo;
        topo.clear();
        return topo;
    }
};