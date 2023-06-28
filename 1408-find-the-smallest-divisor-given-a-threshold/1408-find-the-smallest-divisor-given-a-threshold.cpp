class Solution {
public:
    bool sumofdivision(vector<int>& nums, int K, int mid)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(nums[i]%mid!=0)?(nums[i]/mid)+1:nums[i]/mid;
        }
        if(sum<=K) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int K) {
        int s=1,e=*max_element(nums.begin(),nums.end()),result=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(sumofdivision(nums,K,mid))
            {
                result=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return result;
    }
};