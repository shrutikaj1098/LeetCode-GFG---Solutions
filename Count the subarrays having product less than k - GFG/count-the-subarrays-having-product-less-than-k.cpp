//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long prod=0;
        int count=0;
        int i=0,j=0;
        while(i<n)
        {
            
            if(i==j)
            {
                prod=a[i];
                if(prod<k)count++;
                // cout<<i<<"-"<<j<<endl;
                 if(j<n)j++;
                    else
                {
                    i++;j=i;
                }
            }
            else
            {
                if(prod*a[j]<k &&j<n)
                {
                    count++;
                    prod=prod*a[j];
                    // cout<<i<<"-"<<j<<endl;
                    j++;
                }
                else
                {
                    i++;
                    j=i;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends