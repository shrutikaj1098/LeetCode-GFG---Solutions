//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     bool isPal(string& s){
        for(int i=0,j=s.size()-1;i<j;i++,j--){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
    int helper(string& s,vector<int>& dp,int i=0){
        if(i==s.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        string temp="";
        int tempAns=INT_MAX;
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(isPal(temp)) tempAns=min(tempAns,helper(s,dp,j+1)+1);
        }
        return dp[i]=tempAns;
    }

    int palindromicPartition(string str)
    {
        // code here
        vector<int> dp(str.size(),-1);
        return helper(str,dp)-1;
    }  
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends