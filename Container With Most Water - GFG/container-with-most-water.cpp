//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    // Your code goes here
    long long maxi=0;
    int i=0,j=len-1;
    while(i<j)
    {
        long long base=j-i;
        long long h=min(A[i],A[j]);
        
        long long k=base*h;
        if(k>maxi)
        {
            maxi=k;
        }
        if(A[i]>A[j])
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return maxi;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends