class Solution {
public:
    void solve(vector<int>& nums,int &maxi,int&mini,int i)
    {
        if(i>nums.size()-1)
        {
            return;
        }
        if(mini > nums[i]) mini=nums[i];
        if(nums[i]-mini > maxi) maxi=nums[i]-mini ;
        solve(nums,maxi,mini,i+1);
        
        

    }
    int maxProfit(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        
        solve(nums,maxi,mini,0);
        return maxi;
    }
};