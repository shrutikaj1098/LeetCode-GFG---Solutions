//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool caneat(int N, vector<int>& piles, int H,int mid)
    {
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=(piles[i]/mid)+(piles[i]%mid!=0);
        }
        if(sum<=H) return true;
        else return false;
    }
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int s=0,e=1e9,result=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(caneat(N,piles,H,mid))
            {
                result=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends