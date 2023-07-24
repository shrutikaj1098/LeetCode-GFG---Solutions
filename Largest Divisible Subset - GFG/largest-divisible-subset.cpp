//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& nums) {
        // Code here
        // int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n,1);

        for(int ind=0;ind<n;ind++)
        {
            hash[ind]=ind;
            for(int prev=0;prev<ind;prev++)
            {
                if(nums[ind]%nums[prev]==0 && 1+dp[prev]>dp[ind])
                {
                    dp[ind]=1+dp[prev];
                    hash[ind]=prev;
                }
            }
        }
        int ans=-1;
        int lastindex=-1;
        for(int i=0;i<n;i++)
        {
            if(dp[i]>ans)
            {
                ans=dp[i];
                lastindex=i;
            }
        }
        vector<int> temp;
    temp.push_back(nums[lastindex]);
    
    while(hash[lastindex] != lastindex){ // till not reach the initialization value
        lastindex = hash[lastindex];
        temp.push_back(nums[lastindex]);    
    }
    
    // reverse the array 
    reverse(temp.begin(),temp.end());
    
    // cout<<"The subsequence elements are ";
    
    // for(int i=0; i<temp.size(); i++){
    //     cout<<temp[i]<<" ";
    // }
    // cout<<endl;
    
    return temp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends