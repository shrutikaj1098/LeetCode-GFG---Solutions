//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        int hor=1;
        int ver=1;
        vector<pair<int,int>>v;
        for(auto i:X)
        {
            v.push_back({i,1});
        }
        for(auto i:Y)
        {
            v.push_back({i,0});
        }
        sort(v.rbegin(),v.rend());
        int cost=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].second==1)
            {
                cost+=v[i].first*ver;
                hor++;
            }
            else
            {
                cost+=v[i].first*hor;
                ver++;
            }
        }
        return cost;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends