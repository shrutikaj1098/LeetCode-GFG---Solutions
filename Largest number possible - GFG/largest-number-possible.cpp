//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        vector<int>v(N,0);
        int num=9;
        for(int i=0;i<N;i++)
        {
            num=9;
            if(num<=S)
            {
               v[i]=num;
               S-=num;
            }
            else
            {
                while(num>=0)
                {
                    if(num<=S)
                    {
                       v[i]=num;
                       S-=num;
                       break;
                    }
                    num--;
                }
            }
        }
        
        string s="";
        int nozero=0;
        for(auto i:v)
        {
            s+=to_string(i);
            if(i==0)nozero++;
        }
        if(S!=0 || N>1&&nozero==N) return "-1";
        return s;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends