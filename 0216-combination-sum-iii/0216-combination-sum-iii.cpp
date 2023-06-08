class Solution {
public:
    void combinationhelper(vector<vector<int>>&ans,vector<int>v,int k, int n, int i)
    {
        if( n==0 )
        {
            if(k==0)
            {
                 ans.push_back(v);
            }
           
            return;
        }
        if(i>9) return;
        if(n<0) return;
        
            v.push_back(i);
            combinationhelper(ans,v,k-1,n-i,i+1);
            v.pop_back();
            combinationhelper(ans,v,k,n,i+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v;
        combinationhelper(ans,v,k,n,1);
        return ans;
    }
};