//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N%groupSize!=0)
        {
            return false;
        }
        map<int,int>mp;
        for(int i=0;i<N;i++)
        {
            mp[hand[i]]++;
        }
        vector<int>v(groupSize,0);
        while(mp.size()!=0)
        {
            int curr=mp.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
                if(mp[curr+i]==0) return false;
                else if(--mp[curr+i]<1) mp.erase(curr+i);
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends