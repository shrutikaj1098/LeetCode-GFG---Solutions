//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        vector<bool>prime(N+1,false);
        prime[0]=true;
        prime[1]=true;
        for(int i=2;i<=sqrt(N);i++)
        {
            if(N%i==0)
            {
                N=N/i;
                i--;
            }
        }
        return N;
        
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends