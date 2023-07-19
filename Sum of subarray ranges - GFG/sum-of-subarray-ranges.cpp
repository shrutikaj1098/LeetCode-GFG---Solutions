//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long subarrayRanges(int N, vector<int> &nums) {
        // code here
        int mini,maxi;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            mini=nums[i];maxi=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                mini=min(mini,nums[j]);
                maxi=max(maxi,nums[j]);
                ans+=maxi-mini;
            }

        }
        return ans;
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
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayRanges(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends