class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1,N=nums.size();
        while(s<=e)
        {
            if(nums[s]<=nums[e]) return s;
            int mid=s+(e-s)/2;
            int next=(mid+1)%N;
            int prev=(mid+N-1)%N;
            if(nums[mid]<=nums[next] && nums[mid]<=nums[prev])
            {
                return mid;
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
    int BS(vector<int>& nums, int target,int start, int end)
    {
        int s=start,e=end;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) s=mid+1;
            else e=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
       int index=findMin(nums);
        int x=BS(nums,target, 0,index-1);
        int y=BS(nums,target, index,nums.size()-1);
        if(x==-1 && y==-1) return -1;
        else if(x==-1 && y!=-1) return y;
        else return x;
    }
};