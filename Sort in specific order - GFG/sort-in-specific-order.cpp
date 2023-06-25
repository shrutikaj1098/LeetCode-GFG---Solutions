//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    void sortIt(long long arr[], long long n)
    {
        //code here.
        priority_queue<int>pq;
        priority_queue <int, vector<int>, greater<int>> gq;
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2!=0) pq.push(arr[i]);
            else gq.push(arr[i]);
        }
        
         int i=0;
            while(!pq.empty())
            {
                arr[i++]=pq.top();
                pq.pop();
            }
            while(!gq.empty())
            {
                arr[i++]=gq.top();
                gq.pop();
            }
        
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long arr[n];

        for (int i = 0; i < n; i++) 
            cin >> arr[i];
        
        Solution ob;
        ob.sortIt(arr, n);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends