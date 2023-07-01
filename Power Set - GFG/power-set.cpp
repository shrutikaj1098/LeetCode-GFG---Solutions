//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void findsubset(string v, vector<string>&p,string &nums,int i)
    {
        if(i==nums.size())
        {
            if(v.size()!=0) p.push_back(v);
            return;
        }
        findsubset(v,p,nums,i+1);
        v.push_back(nums[i]);
        findsubset(v,p,nums,i+1);
        v.pop_back();
    }
		vector<string> AllPossibleStrings(string nums){
		    // Code here
		     
            vector<string>p;
            string v="";
            findsubset(v,p,nums,0);
            sort(p.begin(),p.end());
            return p;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends