//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool sumofdivision(vector<int>& nums, int K, int mid)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(nums[i]%mid!=0)?(nums[i]/mid)+1:nums[i]/mid;
        }
        if(sum<=K) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int s=1,e=*max_element(nums.begin(),nums.end()),result=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(sumofdivision(nums,K,mid))
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
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends