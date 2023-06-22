//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
    int maximum(int i, int j,int arr[])
    {
        int maxi=arr[i];
        int maxi_index=i;
        for(int k=i+1;k<=j;k++)
        {
            if(maxi<arr[k])
            {
                maxi=arr[k];
                maxi_index=k;
            }
        }
        return maxi_index;
    }
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int i=0;
        int step=arr[0];
        int mxr=arr[0];
        int jump=1;
        
            if(arr[0]==0)return -1;
            else
            {
                for(int i=1;i<n;i++)
                {
                    if(i==n-1) return jump;
                    else
                    {
                        mxr=max(mxr,i+arr[i]);
                        step--;
                        if(step==0)
                        {
                            jump++;
                            if(i>=mxr) return -1;
                            step=mxr-i;
                        }
                    }
                }
                
            }
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends