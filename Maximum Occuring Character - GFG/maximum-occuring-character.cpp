//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        map<char,int>mp;
        for(auto i:str)
        {
            mp[i]++;
        }
        char c;
        int maxi=INT_MIN;
        for(auto i: mp)
        {
            if(i.second>maxi)
            {
                maxi=i.second;
                c=i.first;
            }
        }
        return c;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends