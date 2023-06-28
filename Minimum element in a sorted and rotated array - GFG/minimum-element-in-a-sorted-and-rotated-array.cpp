//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int A[], int N){
        //complete the function here
         int s=0,e=N-1,smallest=-1,mid;
        sort(A,A+N);
        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(A[s]<=A[e]) return A[s];
            if(A[mid]<=A[mid-1] && A[mid]<=A[mid+1]) smallest=mid;
            if(A[s]<=A[mid])
            {
                s=mid+1;
            }
            else if(A[mid]<=A[e])
            {
                e=mid-1;
            }
        }
        return A[smallest];
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends