class Solution {
public:
    bool checkbatter(int n,vector<int>&batteries, long long mid)
    {
        long long totTime = mid*n;
        
        for(long long bTime : batteries){
            int t= min(mid, bTime);
            totTime -= t;}
           
        
        return (totTime <= 0);
            
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long s=0,e=0;
        int si = batteries.size();
        
        for(int i = 0; i < si; i++){
            e += batteries[i];
        }
        long long ans=0;
        while(s<=e)
        {
            long long mid=s+(e-s)/2;
            if(checkbatter(n,batteries,mid)==true)
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
    }
};