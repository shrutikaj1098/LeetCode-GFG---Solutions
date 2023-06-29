class Solution {
public:

int indexofmaxelement(vector<int>arr, int end) {
	    int max = 0;


	    for ( int i = 0; i <= end; i++){
	        if (arr[i] >= arr[max]){
	            max = i;
	        }
	    }

	    return max;
	}
    vector<int> findPeakGrid(vector<vector<int>>& g) {
        int s=0, e=g.size()-1,mid=0;
    vector<int>v;
    while(s<=e)
    {
        mid=s+(e-s)/2;

        int ans=indexofmaxelement(g[mid],g[mid].size()-1);
        // cout<<ans;
        if(mid==0)
        {
            if(g.size()==1)
            {
                v.push_back(mid);
                 v.push_back(ans);
                 return v;
            }
            if(g[mid][ans]>g[mid+1][ans])
            {
                 v.push_back(mid);
                 v.push_back(ans);
                 return v;
            }
        }
        if(mid==g.size()-1)
        {
            if(g[mid][ans]>g[mid-1][ans])
            {
                 v.push_back(mid);
                 v.push_back(ans);
                 return v;
            }
        }

        if(g[mid][ans]>g[mid+1][ans] && g[mid][ans]>g[mid-1][ans])
        {
            v.push_back(mid);
                 v.push_back(ans);
            return v;
        }
        if( g[mid][ans]<g[mid+1][ans])s=mid+1;
        else e=mid-1;
        
        
    }

    v.push_back(-1);
    v.push_back(-1);
    return v;
    }
};