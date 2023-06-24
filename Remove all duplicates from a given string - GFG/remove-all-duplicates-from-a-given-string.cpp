//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    unordered_map<char,int>mp;
	    int i=0;
	    string tmp="";
	    while(i<str.length())
	    {
	        if(mp.find(str[i])==mp.end())
	        {
	            mp[str[i]]++;
	            tmp+=str[i];
	        }
	        i++;
	    }
	    
	    return tmp;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends