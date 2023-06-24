//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        int i=0,j=S.length()-1;
        int s=0,e=0;
        unordered_map<char,int>mp;
        for( int m=0;m<=j;m++)
        {
            mp[S[m]]++;
        }
        
        bool flag=true;
        while(i<j)
        {
            char a=S[i];
            char b=S[j];
            if(flag)
            {
                if(mp[a]>1)
                {
                    
                    mp[a]--;
                     s=i;
                    flag=false;
                    S[i]='#';
                    // cout<<a<<"Y"<<endl;
                }
                
                i++;
            }
            else
            {
                if(mp[b]>1)
                {
                    
                    mp[b]--;
                    e=j;
                    flag=true;
                    S[j]='#';
                    // cout<<b<<"Z"<<endl;
                }
                // 
                
                j--;
            }
        }
        string ans="";
        for(int i=0;i<S.length();i++)
        {
            if(S[i]!='#')
            {
                ans+=S[i];
            }
        }
        
        if(!flag) {
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends