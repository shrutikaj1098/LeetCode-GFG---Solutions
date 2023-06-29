class Solution {
public:
    int no_of_subarrays_with_max_as_mid( vector<int> &nums, int mid) {
        int sum=0;
        int count=1;
        for(int i=0;i<nums.size();i++)
        {
            if(sum+nums[i]>mid)
            {
                sum=nums[i];
                count++;
            }
            else
            {
                sum+=nums[i];
            }
        }
        return count;
    }

public:
    int splitArray(vector<int>& nums, int m) {
        int s = *max_element(nums.begin(),nums.end()), e = accumulate(nums.begin(),nums.end(),0), ans = INT_MAX;
        // for(int i : nums) e += i;
        
        while(s <= e) {
            int mid = (s + e) / 2;
            int n=no_of_subarrays_with_max_as_mid(nums,mid);
            if(n>m)
            {
                s=mid+1;
            }
            else
            {
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
    }
};