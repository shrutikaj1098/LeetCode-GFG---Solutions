class Solution {
public:
    void permutehelper(vector<int> nums,vector<vector<int>>&ans, int start)
    {
        //base
        if(start==nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int i=start;i<nums.size();i++)
        {
            swap(nums[i],nums[start]);
            permutehelper(nums,ans,start+1);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        // vector<int>v;
        permutehelper(nums,ans,0);
        return ans;
    }
};