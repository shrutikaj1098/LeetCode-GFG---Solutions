//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void generate(vector<int> arr, int N,vector<int> &v,vector<int> p, int i)
    {
        if(i==N)
        {
            if(p.size()==0)
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(accumulate(p.begin(),p.end(),0));
            }
            return;
        }
        generate(arr,N,v,p,i+1);
        p.push_back(arr[i]);
        generate(arr,N,v,p,i+1);
        p.pop_back();
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>v,p;
        generate(arr,N,v,p,0);
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends