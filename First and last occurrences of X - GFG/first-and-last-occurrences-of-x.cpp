//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        int first=-1,last=-1;
        vector<int>v{-1,-1};
        int s=0,e=n-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(arr[mid]>=x)
            {
                if(arr[mid]==x)v[0]=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        s=0,e=n-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(arr[mid]<=x)
            {
                if(arr[mid]==x)v[1]=mid;
                s=mid+1;
                
            }
            else
            {
               e=mid-1;
            }
        }
        if(v[0]==-1 && v[1]==-1) return vector<int>{-1};
        return v;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}

// } Driver Code Ends