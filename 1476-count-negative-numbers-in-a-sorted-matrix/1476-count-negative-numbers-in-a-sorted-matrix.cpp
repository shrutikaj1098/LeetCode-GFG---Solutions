class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            sort(grid[i].begin(),grid[i].end());
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]>=0)break;
                count++;
            }
        }
        return count;
    }
};