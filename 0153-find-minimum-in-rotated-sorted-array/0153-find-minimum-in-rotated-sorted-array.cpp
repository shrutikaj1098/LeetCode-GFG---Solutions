class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1,N=nums.size();
        while(s<=e)
        {
            if(nums[s]<=nums[e]) return nums[s];
            int mid=s+(e-s)/2;
            int next=(mid+1)%N;
            int prev=(mid+N-1)%N;
            if(nums[mid]<=nums[next] && nums[mid]<=nums[prev])
            {
                return nums[mid];
            }
            if(nums[s]<=nums[mid])
            {
                s=(mid+1)%N;
            }
            else if(nums[mid]<=nums[e])
            {
                e=(mid+N-1)%N;
            }
        }
        return -1;
    }
};