//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

 class compare {
      public:
      bool operator() (pair<int,int>&a,pair<int,int>&b) {
          
          return a.second < b.second;
      }
  };
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        vector<int>ans;
        unordered_map<int,int>mpp;
        
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        
        for(auto it:mpp)
        {
            pq.push({it.second,it.first}); // max heap created
        }
        for(int i=0;i<k;i++)
        {
           auto t  = pq.top();
           
           ans.push_back(t.second);
           pq.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends