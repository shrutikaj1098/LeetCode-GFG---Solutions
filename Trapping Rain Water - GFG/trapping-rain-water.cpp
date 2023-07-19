//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        // code here
         
        int maxl[n];
        int maxr[n];
        maxl[0]=height[0];
        for(int i=1;i<n;i++)
        {
            maxl[i]=max(height[i],maxl[i-1]);
        }
        maxr[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxr[i]=max(height[i],maxr[i+1]);
        }
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=min(maxl[i],maxr[i])-height[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends