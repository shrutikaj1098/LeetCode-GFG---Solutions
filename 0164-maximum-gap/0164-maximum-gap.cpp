class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        // if(nums.size()==2) return nums[1]-nums[0];
        sort(nums.begin(),nums.end());
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            int k=i>0?nums[i]-nums[i-1]:0;
            maxi=max(maxi,k);
        }
        return maxi;

    }
};