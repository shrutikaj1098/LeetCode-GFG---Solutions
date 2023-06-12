class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>v;
        
        
        for(int i=0;i<nums.size();i++)
        {
            int left=i;
            int right=i+1;
            while(right<nums.size() && nums[right]==nums[i] + 1)
            {
                i++;
                right++;
            }
            if(left!=i) v.push_back(to_string(nums[left])+"->"+to_string(nums[i]));
            else v.push_back(to_string(nums[left]));
            
        }
        return v;
    }
};