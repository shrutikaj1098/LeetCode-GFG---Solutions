//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findWinner(int N, int x, int y)
	{
		// Your code goes here
		bool dp[N+1];
		dp[0]=0;
		dp[1]=1;
		for(int i=2;i<=N;i++)
		{
		    if(i-1>=0 && !dp[i-1] )dp[i]=1;
		    else if(i-x>=0 &&!dp[i-x]) dp[i]=1;
		    else if(i-y>=0 && !dp[i-y]) dp[i]=1;
		    else dp[i]=0;
		}
		return dp[N];
		
	}

};
	

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends