class Solution {
public:
    bool canloadwiththiscapacity(vector<int>& arr, int N, int D, int mid)
    {
        int days=1,sum=0;
        for(int i=0;i<N;i++)
        {
            if(arr[i]>mid) return false;
            if(sum+arr[i]<=mid)
            {
                sum+=arr[i];
            }
            else
            {
                days++;
                sum=arr[i];
            }
        }
        if(days<=D) return true;
        return false;
        
    }
    int shipWithinDays(vector<int>& arr, int D) {
        int N=arr.size();
        int s=0,e=accumulate(arr.begin(),arr.end(),0),result=-1;;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(canloadwiththiscapacity(arr,N,D,mid))
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