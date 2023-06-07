class Solution {
public:
    void countArrangementhelper(int &n,vector<int>&v, int &ans, int currnum)
    {
        if(currnum==n+1)
        {
            ans++;
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if(v[i]==0 && (i%currnum==0 || currnum%i==0))
            {
                v[i]=currnum;
                countArrangementhelper(n,v,ans,currnum+1);
                v[i]=0;
            }
            
        }
    }
    int countArrangement(int n) {
        vector<int>v(n+1);
        int ans=0;
        countArrangementhelper(n,v, ans,1);
        return ans;
    }
};