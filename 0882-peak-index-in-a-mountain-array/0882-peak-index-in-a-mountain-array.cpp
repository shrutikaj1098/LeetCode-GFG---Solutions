class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int s=0,e=n-1;
        while(s<e)
        {
            int mid=s+(e-s)/2;
            if(mid-1>=0 && mid+1<n && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                return mid;
            }
            if(arr[mid-1]>arr[mid] && mid-1>=0)
            {
                e=mid;
            }
            else if(arr[mid+1]>arr[mid] && mid+1<n)
            {
                s=mid+1;
            }
        }
        return -1;
    }
};