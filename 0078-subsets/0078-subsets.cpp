class Solution {
public:
    void findsubset(vector<vector<int>>&v, vector<int>p,vector<int>&nums,int i)
    {
        if(i==nums.size())
        {
            v.push_back(p);
            return;
        }
        findsubset(v,p,nums,i+1);
        p.push_back(nums[i]);
        findsubset(v,p,nums,i+1);
        p.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>p;
        findsubset(v,p,nums,0);
        return v;
    }
};