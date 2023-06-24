//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    map<char,int>mp;
    int i=0,j=0;
    int maxi=INT_MIN;
    int val=0;
    while(i<S.length())
    {
        if(mp.find(S[i])==mp.end())
        {
            
            mp[S[i]]++;
            val++;
            // cout<<val<<endl;
            i++;
        }
        else if(mp[S[i]]==0)
        {
            mp[S[i]]++;
            val++;
            i++;
        }
        else
        {
            maxi=max(maxi,val);
            mp[S[j]]--;
            val--;
            j++;
        }
    }
    maxi=max(maxi,val);
    return maxi;
}