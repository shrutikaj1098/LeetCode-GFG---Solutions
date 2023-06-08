class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int poscount=0,negcount=0;
        if(nums[0]==0 &&nums[nums.size()-1]==0)
          return 0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]<0)
            {
                negcount=mid;
                s=mid+1;
            }
            else if(nums[mid]>=0)
            {
                e=mid-1;
            }
            
        }
        
        
        int totalnegcount=negcount-0+1;
        s=0;
         e=nums.size()-1;
        
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]>0)
            {
                poscount=mid;
                cout<<mid<<"YO"<<endl;
                e=mid-1;
            }
            else if(nums[mid]<=0)
            {
                s=mid+1;
                
            }
            
        }
        int endpos=0;
        if(nums[nums.size()-1]>0)
        {
            endpos=nums.size()-1;
        }
        
         int totalposcount=endpos-poscount+1;
         cout<<totalposcount<<" "<<totalnegcount;
         return max(totalposcount,totalnegcount);
    }
};