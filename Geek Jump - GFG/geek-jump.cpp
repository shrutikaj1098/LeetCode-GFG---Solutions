//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int rec(vector<int>&heights, int ind,vector<int>&dp)
    {
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int fs=rec(heights,ind-1,dp)+abs(heights[ind]-heights[ind-1]);
        int ss=INT_MAX;
        if(ind>1)   ss=rec(heights,ind-2,dp)+abs(heights[ind]-heights[ind-2]);
        
        return dp[ind]=min(fs,ss);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1,-1);
        return rec(height,n-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends