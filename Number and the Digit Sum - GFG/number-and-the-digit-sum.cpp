//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        bool check(long long int n, long long int K)
        {
            long long int ans=0;
            long long int a=n;
            while(n)
            {
                ans+=n%10;
                n/=10;
            }
            return (a-ans)>=K;
        }
        long long int numberCount(long long int N, long long int K)
        {
            // your code here
            long long int c=0;
            
            long long int s=0,e=N;
            while(s<=e)
            {
                long long int mid=s+(e-s)/2;
                // cout<<mid<<endl;
                if(check(mid,K))
                {
                    c+=e-mid+1;
                    e=mid-1;
                    
                }
                else
                {
                    s=mid+1;
                }
                // cout<<s;
            }
            return c;
            
        }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n, k;
		cin >> n >> k;
		Solution ob;
		cout <<ob.numberCount(n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends