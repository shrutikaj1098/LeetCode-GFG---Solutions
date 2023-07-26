class Solution {
public:

    bool checkhour(vector<int>&dist, double hour, int mid)
    {
        double ans=0.0;
        for(int i=0;i<dist.size();i++)
        {
            if(i!=dist.size()-1)  ans+=ceil((double)dist[i]/(double)mid);
            else ans+=((double)dist[i]/(double)mid);
        }
        if(ans<=hour) return true;
        else return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int s=0,e=1e7;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            // cout<<mid<<endl;
            if(checkhour(dist,hour,mid)==true)
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
};