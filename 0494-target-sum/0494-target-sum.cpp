class Solution {
public:
    int rec(vector<int>&A ,int target, int ind)
    {
        if(ind==0)
        {
            if(target - A[0] == 0 and target + A[0] == 0) return 2;
            if(target-A[0]==0) return 1;
            if(target+A[0]==0) return 1;
            return 0;
        }
        
        int n=-A[ind]+rec(A,target-A[ind],ind-1);
        int p=A[ind]+rec(A,target+A[ind],ind-1);
        
        return n+p;
    }
    int findTargetSumWays(vector<int>& A, int target) {
        return rec(A,target,A.size()-1);
    }
};