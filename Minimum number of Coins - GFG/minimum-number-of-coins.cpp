//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int rec(int target, int ind, vector<int>&v,vector<int>&ans)
    {
        if(ind==0)
        {
            if(target%v[ind]==0)
            {
                for(int i=0;i<target/v[ind];i++) ans.push_back(v[ind]);
                return target/v[ind];
            }
             return 1e9 ;
        }
        int np=rec(target,ind-1,v,ans);
        int p=1e9;
        if(v[ind]<=target)
        {
            ans.push_back(v[ind]);
            p=1+rec(target-v[ind],ind,v,ans);
            ans.pop_back();
        }
        return min(p,np);
    }
    vector<int> minPartition(int N)
    {
        // code here
        vector<int>v{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        int n=v.size()-1;
        vector<int>ans;
        int amount=N;
        // rec(N,n-1,v,ans);
        // return ans;
        while(n>=0 && amount>0 )
        {
            if(v[n]<=amount)
            {
                amount-=v[n];
                ans.push_back(v[n]);
            }
            else
            {
                n--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends