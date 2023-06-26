class Solution {
public:
    int reachNumber(int target) {
      long long mid=0;
        long long count=0;
        target=abs(target);
        while(1)
        {
            count++;
            mid=mid+count;
            if(mid>=target && (mid-target)%2==0 )
            {
                break;
            }
        }
        return count;
    }
};