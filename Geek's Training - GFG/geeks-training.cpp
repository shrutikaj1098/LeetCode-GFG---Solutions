//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int rec(vector<vector<int>>& points, int i, int last,  vector<vector<int>>&dp)
    {
        if(dp[i][last]!=-1) return dp[i][last];
        if(i==0)
        {
            int maxi=INT_MIN;
            for(int j=0;j<3;j++)
            {
                if(j!=last)
                {
                    maxi=max(points[0][j],maxi);
                }
            }
            return dp[i][last]=maxi;
        }
        
        int maxi=INT_MIN;
        for(int j=0;j<3;j++)
        {
                if(j!=last)
                {
                    int point=points[i][j]+rec(points,i-1,j,dp) ;
                    maxi=max(point,maxi);
                }
        }
        return  dp[i][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return rec(points, n-1,3,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends