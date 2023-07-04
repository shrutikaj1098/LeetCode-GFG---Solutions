class Solution {
public:
    int rec(string&s, string&t, int i, int j,vector<vector<int>>&dp)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=rec(s,t,i-1,j-1,dp);
        else
        {
            return dp[i][j]= 1+min(rec(s,t,i-1,j,dp),min(rec(s,t,i,j-1,dp),rec(s,t,i-1,j-1,dp)));
        }
    }
    int minDistance(string s, string t) {
        int i=s.length(),j=t.length();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        return rec(s,t,i,j,dp);
    }
};