class Solution {
public:
    void merge(vector<int>&nums,int s,int e, int mid)
    {
        
        int len1=mid-s+1;
        int len2=e-mid;
        vector<int>left(len1);
        vector<int>right(len2);
        int k=s;
        for(int i=0;i<len1;i++)
        {
            left[i]=nums[k++];
        }
        for(int i=0;i<len2;i++)
        {
            right[i]=nums[k++];
        }
        int leftindex=0;
        int rightindex=0;
        int mainindex=s;
        while(leftindex<len1 && rightindex<len2)
        {
            if(left[leftindex]<=right[rightindex])
            {
                nums[mainindex++]=left[leftindex++];
            }
            else
            {
                 nums[mainindex++]=right[rightindex++];
            }
        }
        while(leftindex<len1)
        {
            nums[mainindex++]=left[leftindex++];
        }
        while(rightindex<len2)
        {
            nums[mainindex++]=right[rightindex++];
        }
        left.clear();
        right.clear();
    }
    void mergesort(vector<int>&nums,int s,int e)
    {
        if(s>=e)
        {
            return;
        }
        int mid=s+(e-s)/2;
        mergesort(nums,s,mid);
        mergesort(nums,mid+1,e);

        merge(nums,s,e,mid);
    }
    vector<int> sortArray(vector<int>& nums) {
       int s=0;
       int e=nums.size()-1;
       mergesort(nums,s,e);
       return nums;
    }
};