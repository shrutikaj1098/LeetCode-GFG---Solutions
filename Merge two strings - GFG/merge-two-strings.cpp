//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string merge (string s1, string s2);

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << merge (s1, s2) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends



string merge (string S1, string S2)
{
    // your code here
    if(S1.empty()) return S2;
    if(S2.empty()) return S1;
    int n=S1.length();
    int m=S2.length();
    int i=0,j=0;
    if(n>m)
    {
        j=1;
        for(int i=0;i<m;i++)
        {
            S1.insert(j,1,S2[i]);
            j+=2;
        }
        return S1;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            S2.insert(j,1,S1[i]);
            j+=2;
        }
        return S2;
    }
    
}