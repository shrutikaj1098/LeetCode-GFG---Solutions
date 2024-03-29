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
        unordered_map<int,bool>visited;
        for(int i=start;i<nums.size();i++)
        {
            if(visited.find(nums[i])!=visited.end()) continue;
            visited[nums[i]]=true;
            swap(nums[i],nums[start]);
            permutehelper(nums,ans,start+1);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>>ans;
        // vector<int>v;
        permutehelper(nums,ans,0);
        // set<vector<int>>s;
        // for(auto i:ans)
        // {
        //     s.insert(i);
        // }
        // ans.clear();
        // for(auto i:s)
        // {
        //     ans.push_back(i);
        // }
        return ans;

    }
};