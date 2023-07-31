class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // for(int i=0;i<=n;i++)dp[i][0]=0;
        // for(int i=0;i<=m;i++)dp[0][i]=0;

       for(int i=1 ; i<=n;i++)
       {
           for(int j=1;j<=m ;j++)
           {
               if(s1[i-1]==s2[j-1]) dp[i][j]=s1[i-1]+dp[i-1][j-1];
               else
               {
                   dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
               }
           }
       }
        // int length=dp[n][m];
        int l=dp[n][m];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(int)s1[i];
        }
        int sum2=0;
        for(int i=0;i<m;i++)
        {
            sum2+=(int)s2[i];
        }
        return sum+sum2-2*l;
    }
};