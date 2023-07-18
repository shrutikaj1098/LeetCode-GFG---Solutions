//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int mod =1000000007;
	    int rec(string s, int index, vector<int>&dp)
    {
        
        if(index==s.size()) return 1;
        if(s[index]=='0') return 0;
        if(dp[index]!=-1) return dp[index];
        int nt=rec(s,index+1,dp);
        int t=0;
        if(index<s.size()-1 && (s[index]=='1' ||(s[index]=='2' && s[index+1]<='6')))
        {
            t=rec(s,index+2,dp);
        }
        return dp[index]=(t+nt)%mod;

    }
		int CountWays(string s){
		    // Code here
		      vector<int>dp(s.size()+1,-1);
        return rec(s,0,dp)%mod;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends