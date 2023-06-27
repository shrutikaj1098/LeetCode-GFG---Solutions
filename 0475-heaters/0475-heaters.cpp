class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        int radius=0;
        sort(heaters.begin(),heaters.end());
        for(int i=0;i<houses.size();i++)
        {
            
            int x=lower_bound(heaters.begin(),heaters.end(),houses[i])-heaters.begin();
            if(x==heaters.size()){x--;}

            int leftdiff=(x-1>=0)?abs(houses[i]-heaters[x-1]):INT_MAX;
            int rightdiff=abs(houses[i]-heaters[x]);
            radius=max(radius,min(leftdiff,rightdiff));

        }
        
        return radius;
        
    }
};