class Solution {
public:
    void marktrue(int k, vector<int>&v ,int n)
    {
        for(int i=2*k; i<=n; i=i+k)
        {
            v[i]=1;
        }
    }
    int countPrimes(int n) {
        int count=0;
        vector<int>v(n+1,0);
       
        for(int i=2;i<n;i++)
        {
            if(v[i]!=1)
            {
                count++;
                marktrue(i,v,n);
            }
            
        }
        
        return count;
    }
};