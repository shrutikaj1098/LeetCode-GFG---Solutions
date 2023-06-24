//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        
        reverse(X.begin(),X.end());
        reverse(Y.begin(),Y.end());
        if(Y.size()>X.size())
        {
            swap(Y,X);
        }
        int i=0,j=0,carry=0;
        while(i<X.size() && j<Y.size())
        {
            int ans=X[i]-'0'+Y[i]-'0'+carry;
            carry=ans/10;
            X[i]='0'+(ans%10);
            i++;j++;
        }
        while(i<X.size())
        {
            int ans=X[i]-'0'+carry;
            carry=ans/10;
            X[i]='0'+(ans%10);
            i++;
        }
        if(carry>0) 
        {
            X.push_back('0'+carry%10);
            carry=carry/10;
        }
        while(X.size() && X.back()=='0')
        {
            X.pop_back();
            
        }
        reverse(X.begin(),X.end());
        if(X.size()==0)
        {
            return "0";
        }
        else
        {
            return X;
        }
        
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends