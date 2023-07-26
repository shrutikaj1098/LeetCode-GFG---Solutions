class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>q;
        vector<pair<int,int>>adj[n+1]; 
        
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
        }
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        q.push({0,k});
        while(!q.empty())
        {
            auto i=q.top();q.pop();
            int node=i.second;
            int time=i.first;

            for(auto it: adj[node])
            {
                int adjn=it.first;
                int t=it.second;
                if(t+time<dist[adjn])
                {
                    dist[adjn]=t+time;
                    q.push({dist[adjn],adjn});
                }
            }
        }
         int maxi=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9)return -1;
            maxi=max(maxi,dist[i]);
        }
        return maxi;
    }
};