//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        priority_queue<pair<int, char>>mxh;
        map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
           
        }
        for(auto i: mp)
        {
            mxh.push({i.second,i.first});
        }
        while(k>0)
        {
            if(mp[mxh.top().second]!=-2)
            {
                auto it=mxh.top();
                mxh.pop();
                mp[it.second]--;
                mxh.push({mp[it.second],it.second });
                if(mp[it.second]==0) mp[it.second]=-2;
                k--;
                
            }
            else
            {
                mxh.pop();
            }
        }
        int ans=0;
        while(!mxh.empty())
        {
            auto it=mxh.top();
            mxh.pop();
            // cout<<it.first<<it.second<<endl;
            ans+=it.first * it.first;
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends