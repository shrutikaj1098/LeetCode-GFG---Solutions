//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        
        vector<bool>mp(leaves+1 ,0);
        int i=0;
        while(i<N)
        {
            int jump=frogs[i];
            if(frogs[i]==1) return 0;
            if(mp[jump]!=1)
            {
                while(jump<=leaves)
                {
                    mp[jump]=1;
                    jump+=frogs[i];
                }
               
            }
            i++;
            
            
            
        }
        int count=0;
        for(auto j:mp)
        {
            if(j==0) count++;
        }
        return count-1;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends