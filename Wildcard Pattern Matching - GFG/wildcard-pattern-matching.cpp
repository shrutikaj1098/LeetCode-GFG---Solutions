//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool solve(int ind1,int ind2,string &s,string &p,vector<vector<int>> &dp){
        if(ind1<0 && ind2<0) return true;
        if(ind2<0) return false;
        if(ind1<0){
            for(int i=0;i<=ind2;i++){
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s[ind1]==p[ind2] || p[ind2]=='?') return dp[ind1][ind2]=solve(ind1-1,ind2-1,s,p,dp);
        else if(p[ind2]=='*'){
            return dp[ind1][ind2]=solve(ind1-1,ind2,s,p,dp) || solve(ind1,ind2-1,s,p,dp);
        }
        return dp[ind1][ind2]=false;
    }
    int wildCard(string pattern,string str)
    {
        int n=str.length();
        int m=pattern.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,str,pattern,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends