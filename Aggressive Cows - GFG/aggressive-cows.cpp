//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool canplacecowsatmid(int n, int k, vector<int> &stalls, int mid)
    {
        int cow=1,dist=stalls[0];
        for(int i=1;i<n;i++)
        {
            if(stalls[i]-dist>=mid)
            {
                cow++;
                dist=stalls[i];
            }
            
            if(cow==k) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int s=0,e=stalls[n-1]-stalls[0],result=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(canplacecowsatmid(n,k,stalls,mid))
            {
                result=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends