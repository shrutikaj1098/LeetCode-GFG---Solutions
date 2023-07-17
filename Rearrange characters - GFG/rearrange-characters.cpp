//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string s)
    {
        //code here
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>q;
        for(auto i:s)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            q.push(make_pair(i.second,i.first));
        }
        string ans="";
        while(q.size()>1)
        {
            auto top1=q.top();
            q.pop();
            auto top2=q.top();
            q.pop();
            ans+=top1.second;
            ans+=top2.second;
            top1.first-=1;
            top2.first-=1;
            if(top1.first>0)
            {
                q.push(make_pair(top1.first,top1.second));
            }
            if(top2.first>0)
            {
                q.push(make_pair(top2.first,top2.second));
            }
        }
        if(!q.empty())
        {
            if(q.top().first>1)
            {
                return "-1";
            }
            else
            {
                return ans+=q.top().second;
            }
        }
        return ans;
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
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends