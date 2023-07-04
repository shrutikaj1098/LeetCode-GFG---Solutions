class Solution {
public:
    int rec(string &X, string &Y,int i,int j,vector<vector<int>>&dp)
    {
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(X[i-1]==Y[j-1]) return dp[i][j]=1+rec(X,Y,i-1,j-1,dp);
        return dp[i][j]=max(rec(X,Y,i-1,j,dp),rec(X,Y,i,j-1,dp));
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.length(),n=str2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        cout<<rec(str1,str2,m,n,dp);
        int len = dp[m][n];
        int i = m;
        int j = n;

        // int index = len - 1;
        string ans = "";

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
            ans += str1[i-1];
            // index--;
            i--;
            j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += str1[i-1];
                i--;
            } else {
                ans += str2[j-1];
                j--;
            }
        }
        
        //Adding Remaing Characters - Only one of the below two while loops will run 
        
        while(i>0){
            ans += str1[i-1];
            i--;
        }
        while(j>0){
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(),ans.end());
        
        return ans;

    }
};