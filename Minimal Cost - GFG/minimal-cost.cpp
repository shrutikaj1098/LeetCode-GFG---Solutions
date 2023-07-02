//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int rec(vector<int>& height, int ind, int k,vector<int>&dp)
    {
        if(ind<=0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            int jump=INT_MAX;
            if(ind-j>=0)jump=abs(height[ind]-height[ind-j])+rec(height,ind-j,k,dp);
            ans=min(ans,jump);
        }
        return dp[ind]=ans;
        
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n+1,-1);
        return rec(height,n-1,k,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends