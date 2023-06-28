//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool canloadwiththiscapacity(int arr[], int N, int D, int mid)
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
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int s=0,e=accumulate(arr,arr+N,0),result=-1;;
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends