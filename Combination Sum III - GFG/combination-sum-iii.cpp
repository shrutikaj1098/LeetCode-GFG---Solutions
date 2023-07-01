//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void generate(vector<int>&nums,int K,int N,vector<vector<int>>&v , vector<int>p,int ind)
    {
        if(N==0)
        {
            if(p.size()==K )
            {
                v.push_back(p);
            }
            return;
        }
        if(N<0 || ind==nums.size()) return;
        for(int i=ind;i<nums.size();i++ )
        {
            if(nums[i]>N) break;
            p.push_back(nums[i]);
            generate(nums,K,N-nums[i],v,p,i+1);
            p.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<int>nums;
        for(int i=1;i<=9;i++)
        {
            nums.push_back(i);
        }
        vector<vector<int>>v;
        vector<int>p;
        generate(nums,K,N,v,p,0);
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends