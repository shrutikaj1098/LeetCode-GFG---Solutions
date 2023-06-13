class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int>mp;
        for(int i=0;i<grid.size();i++)
        {
            mp[grid[i]]++;
        }
        int count=0;
        vector<vector<int>>col;
        for(int i=0;i<grid.size();i++)
        {
            vector<int>temp;
            for(int j=0;j<grid[0].size();j++)
            {
                temp.push_back(grid[j][i]);
            }
            col.push_back(temp);
        }
        for(int j=0;j<col.size();j++)
        {
            if(mp.find(col[j])!=mp.end())
            {
                count+=mp[col[j]];
            }
        }
        return count;
    }
};