class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int s=0, n=arr.size()-1,e=n;
        if(arr.size()==1) return 0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(mid>0 && mid<n)
            {
                if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
                else if(arr[mid+1]>arr[mid]) s=mid+1;
                else e=mid-1;
            }
            else if(mid==0)
            {
                if(arr[0]>arr[1]) return 0;
                else return 1;
            }
            else if(mid==n)
            {
                if(arr[n]>arr[n-1]) return n;
                else return n-1;
            }
        }
        return -1;
    }
};