//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        vector<int>v(26,-1);
        int maxi=INT_MIN;
        int val=0,l=0;
        for(int i=0;i<S.length();i++)
        {
            int k=S[i]-'a';
            // cout<<k;
            if(v[k]!=-1)
            {
                l=max(v[k]+1,l);
                
            }
            v[k]=i;
            maxi=max(i-l+1,maxi);
        }
        return maxi;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends