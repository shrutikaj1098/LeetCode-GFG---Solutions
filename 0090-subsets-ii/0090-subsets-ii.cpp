class Solution {
public:
void solve(int ind, vector<int>&nums, vector<int>&ds, vector<vector<int>>&ans){
        ans.push_back(ds);
        int n=nums.size();
        for(int i=ind; i<n; i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            solve(i+1, nums, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(), nums.end());
        solve(0, nums, ds, ans);
        return ans;
    }
};