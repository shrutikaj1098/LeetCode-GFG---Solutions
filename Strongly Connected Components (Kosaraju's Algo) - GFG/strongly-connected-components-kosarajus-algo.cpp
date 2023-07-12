//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void dfs(int node, vector<bool> &visited, const vector<vector<int>>& adj, stack<int> &st) {
        visited[node] = true;
    
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, visited, adj, st);
            }
        }
    
        st.push(node);
    }

    void dfsAgain(int node, vector<bool> &visited, const vector<vector<int>>& adj) {
        visited[node] = true;
    
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfsAgain(it, visited, adj);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<bool> visited(V, false);
        stack<int> st;
    
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, st);
            }
        }
    
        vector<vector<int>> adjR(V);
        adjR.reserve(V); // Preallocate memory for the adjR vector
    
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjR[it].push_back(i);
            }
        }
    
        int scc = 0;
    
        fill(visited.begin(), visited.end(), false); // Reinitialize visited vector
    
        while (!st.empty()) {
            int node = st.top();
            st.pop();
    
            if (!visited[node]) {
                scc++;
                dfsAgain(node, visited, adjR);
            }
        }
    
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends