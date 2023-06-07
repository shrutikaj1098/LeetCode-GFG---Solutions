class Solution {
public:
    void combinationSum2helper(vector<int>& arr, int target, vector<vector<int>>&ans,vector<int>ds, int index)
    {
        if(target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for(int i = index; i< arr.size();i++)
    {
       if(i > index && arr[i] == arr[i-1])
       continue;

       if(arr[i] > target)
       break;

       ds.push_back(arr[i]);
       combinationSum2helper(arr,target-arr[i],ans,ds,i+1);
       ds.pop_back();
    }

    return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
       sort(candidates.begin(),candidates.end());
        combinationSum2helper(candidates,target,ans,v,0);
        set<vector<int>>s;
        for(auto i:ans)
        {
            s.insert(i);
        }
        vector<vector<int>>ans2;
        for(auto i:s)
        {
            ans2.push_back(i);
        }
        return ans2;
    }
};