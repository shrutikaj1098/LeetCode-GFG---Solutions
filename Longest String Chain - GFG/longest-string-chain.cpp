//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(string &s1, string &s2)
    {
        if(s1.size()!=s2.size()+1) return 0;
        int f=0,s=0;
        while(f<s1.size())
        {
            if(s1[f]==s2[s])
            {
                f++;s++;
            }
            else
            f++;
        }
        if(f==s1.size() && s==s2.size()) return 1;
        return 0;
    }
    static bool com(string &s1, string &s2)
    {
        return s1.size()<s2.size();
    }
    int longestChain(int n, vector<string>& nums) {
        // Code here
        sort(nums.begin(),nums.end(),com);
        vector<int>dp(n,1);
        int maxi=INT_MIN;
        for(int ind=0;ind<n;ind++)
        {
            for(int prev=0;prev<ind;prev++)
            {
                if(check(nums[ind],nums[prev]) && 1+dp[prev]>dp[ind])
                {
                    dp[ind]=1+dp[prev];
                    
                }
            }
            maxi=max(maxi,dp[ind]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends