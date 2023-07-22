//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int dr[8]={-2,+2,-2,+2,-1,+1,-1,+1};
    int dc[8]={-1,+1,+1,-1,-2,+2,+2,-2};
    double rec(int n, int k, int r, int c,vector<vector<vector<double>>>&dp)
    {
        if(r>=n || c>=n || r<0 || c<0) return 0;
        if(k==0) return 1;
        if(dp[r][c][k]!=-1) return dp[r][c][k];
        double ans=0;
        for(int i=0;i<8;i++)
        {
            int newr=dr[i];
            int newc=dc[i];
            ans+=rec(n,k-1,r+newr,c+newc,dp);
        }

        return dp[r][c][k]=ans;


    }
	double findProb(int n,int row, int column, int k)
	{
	    // Code here
	    vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        
        double ans=rec(n,k,row,column,dp);
        double total=pow(8,k);
        return ans/total;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends