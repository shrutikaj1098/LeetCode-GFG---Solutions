//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool compare(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
        
    }
    int minRemoval(int N, vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(),intervals.end(),compare);
        int n=intervals.size();
        vector<vector<int>>merge;
        int tot=0;
        for(int i=0;i<n;i++)
        {
           if(merge.empty() || merge.back()[1]<= intervals[i][0] )
           {
               merge.push_back({intervals[i][0],intervals[i][1]});
           }
           else if(merge.back()[1]>intervals[i][0])
           {
               tot++;
               merge.back()[1]=min(merge.back()[1],intervals[i][1]);
           }
        }
        return tot;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends