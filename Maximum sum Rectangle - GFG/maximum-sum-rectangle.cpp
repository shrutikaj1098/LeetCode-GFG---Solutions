//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int kadene(vector<int>&ans, int C)
    {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<C;i++)
        {
            sum+=ans[i];
            if(maxi<sum)
            {
                maxi=sum;
            }
            if(sum<0) sum=0;
            
        }
        return maxi;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int ma=INT_MIN;
        for(int i=0;i<R;i++)
        {
            vector<int>ans(C);
            for(int j=i;j<R;j++)
            {
                for(int k=0;k<C;k++)
                {
                    ans[k]+=M[j][k];
                }
                ma=max(ma,kadene(ans,C));
            }
        }
        return ma;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends