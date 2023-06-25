//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countZeroes(int arr[], int n) {
        // code here
        int s=0,e=n-1;
        int firstindex=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(arr[mid]==0)
            {
                firstindex=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        if(firstindex==-1) return 0;
        return n-firstindex;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countZeroes(arr, n);
        cout << ans << "\n";
    }
    return 0;
}


// } Driver Code Ends