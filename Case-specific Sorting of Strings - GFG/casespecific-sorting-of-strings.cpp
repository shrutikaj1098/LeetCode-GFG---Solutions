//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string m=str;
        sort(str.begin(),str.end());
        vector<char>v,s;
        for(int i=0;i<n;i++)
        {
            if(str[i]>='a' && str[i]<='z')
            {
                v.push_back(str[i]);
            }
            else
            {
                s.push_back(str[i]);
            }
        }
        int j=0,k=0;
        for(int i=0;i<n;i++)
        {
            if(m[i]>='a' && m[i]<='z')
            {
                // cout<<v[j]<<endl;
                m[i]=v[j];
                j++;
            }
            else
            {
                // cout<<s[k]<<endl;
                m[i]=s[k];
                k++;
            }
        }
        v.clear();
        s.clear();
        return m;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends