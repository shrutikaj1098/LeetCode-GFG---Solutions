//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumSubarrayMins(int n, vector<int> &arr) {
        // code here
        int sum=0;
        int mod=1000000007;
        stack<int>s;
        vector<int>dp(n,0);
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            if(s.size()>0)
            {
                int prev=s.top();
                dp[i]=dp[prev]+(i-prev)*arr[i];
            }
            else
            {
                dp[i]=(i+1)*arr[i];
            }
            s.push(i);
        }
        for(int i=0;i<n;i++)
        {
            sum+=dp[i];
            sum%=mod;
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends