//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    string reverse(string s)
    { 
        //code here.
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if((s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z') && (s[j]>='a' && s[j]<='z' || s[j]>='A' && s[j]<='Z'))
            {
                swap(s[i],s[j]);
                i++;j--;
            }
            else if((s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z') && !(s[j]>='a' && s[j]<='z' || s[j]>='A' && s[j]<='Z'))
            {
                j--;
            }
            else if(!(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z') && (s[j]>='a' && s[j]<='z' || s[j]>='A' && s[j]<='Z'))
            {
                i++;
            }
            else
            {
                i++;j--;
            }
        }
        return s;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.reverse(s) << endl;
    }
return 0;
}


// } Driver Code Ends