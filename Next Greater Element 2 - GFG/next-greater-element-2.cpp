//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& a) {
        // code here
        vector<int>v,t,k;
    stack<int>s;
    t=a;
    for(int i=0;i<a.size();i++ )
    {
        t.push_back(a[i]);
    }
    for(int i=t.size()-1;i>=0;i--)
    {
        if(s.empty())
        {
            v.push_back(-1);
        }
        else if(!s.empty() && s.top()>t[i])
        {
            v.push_back(s.top());
        }
        else if(!s.empty() && s.top()<=t[i])
        {
            while(!s.empty() && s.top()<=t[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                v.push_back(-1);
            }
            else v.push_back(s.top());
        }
        s.push(t[i]);

    }
    reverse(v.begin(),v.end());
    for(int i=0;i<a.size();i++)
    {
        k.push_back(v[i]);
    }
    return k;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends