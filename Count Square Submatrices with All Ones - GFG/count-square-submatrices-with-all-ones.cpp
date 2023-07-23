//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSquares(int n, int m, vector<vector<int>> &matrix) {
        // // code here
        // int n=matrix.size();
        // int m=matrix[0].size();
        int sum=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++) {dp[i][0]=matrix[i][0];}
        for(int j=0;j<m;j++) {;dp[0][j]=matrix[0][j];}
        
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==1)
                {int up=dp[i-1][j];
                int left=dp[i][j-1];
                int upd=dp[i-1][j-1];
                dp[i][j]=min(up,min(left,upd))+1;}
                else dp[i][j]=0;
            }
           
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                sum+=dp[i][j];
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.countSquares(N, M, matrix) << endl;
    }
    return 0;
}
// } Driver Code Ends