class Solution {
public:
    int minInsertions(string s) {
       string t=s;
    reverse(t.begin(),t.end());
    int n=s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    return n-dp[n][n];  
    }
};