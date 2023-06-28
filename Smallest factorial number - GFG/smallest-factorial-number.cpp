//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        int ischeck(int mid)
        {
            int sum=0;
            while(mid/5>0)
            {
                sum+=mid/5;
                mid/=5;
            }
            return sum;
        }
        int findNum(int n)
        {
        //complete the function here
            int sum=0;
            int s=0,e=5*n;
            while(s<=e)
            {
                int mid=s+(e-s)/2;
                if(ischeck(mid)>=n)
                {
                    sum=mid;
                    e=mid-1;
                }
                else s=mid+1;
            }
            return sum;
        
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends