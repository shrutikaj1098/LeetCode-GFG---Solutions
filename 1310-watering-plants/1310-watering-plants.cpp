class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int i=0;
        int count=0;
        int e=capacity;
        while(i<plants.size())
        {
            
            if(capacity>=plants[i])
            {
                count++;
                capacity-=plants[i];
            }
            else
            {
                count+=i+1;
                capacity=e;
                count+=i;
                capacity-=plants[i];
            }
            i++;
        }
        return count;
    }
};