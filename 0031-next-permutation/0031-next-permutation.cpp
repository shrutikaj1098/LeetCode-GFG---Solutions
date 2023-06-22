class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find first decresing element from last
        int flag=false;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                cout<<"Y";
                flag=true;
                int j=i;
                while(j<nums.size() && nums[j]>nums[i-1])
                {
                    j++;
                }   
                swap(nums[j-1],nums[i-1]);
                reverse(nums.begin()+i,nums.end());
                break;             
            }
        }
        if(flag==false)
        {
            sort(nums.begin(),nums.end());
        }
    }
};