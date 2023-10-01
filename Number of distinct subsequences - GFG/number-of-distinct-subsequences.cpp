//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
    set<string>se;
    void rec(string s, int i,string op)
    {
        if(i<0) 
        {
            se.insert(op);
            return;
        }
        rec(s,i-1,op);
        op.push_back(s[i]);
        rec(s,i-1,op);
        op.pop_back();
        
        // return t+nt;
    }
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	   //  rec(s,s.size()-1,"");
	   //  se.size()%1e9;
	   int mod = 1000000007;
	    int n = s.length();
	    vector<int>dp(n+1);
	    dp[0] =1;
	    
	    unordered_map<char,int>mp;
	    for(int i=1; i<=n;i++){
	        char ch = s[i-1];
	        dp[i] = (2*dp[i-1])%mod;
	        if(mp.find(ch)!=mp.end()){
	            int index = mp[ch];
	            dp[i] = (dp[i]-dp[index-1]+mod)%mod;
	        }
	        mp[ch] =i;
	    }
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends