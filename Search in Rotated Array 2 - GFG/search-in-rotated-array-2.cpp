//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int BS(vector<int>&A,int N, int s, int e, int k)
    {
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(A[mid]==k) return mid;
            else if(A[mid]<k)s=mid+1;
            else e=mid-1;
        }
        return -1;
    }
    bool Search(int N, vector<int>& A, int Key) {
        // Code here
        int s=0,e=N-1,smallest=-1,mid;
        sort(A.begin(),A.end());
        while(s<=e)
        {
            mid=s+(e-s)/2;
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
        int t=BS(A,N,0,mid-1,Key);
        int m=BS(A,N,mid,N-1,Key);
        if(t==-1 && m==-1) return 0;
        else return 1;
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
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends