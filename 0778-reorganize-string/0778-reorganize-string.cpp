class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>q;
        for(auto i:s)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            q.push(make_pair(i.second,i.first));
        }
        string ans="";
        while(q.size()>1)
        {
            auto top1=q.top();
            q.pop();
            auto top2=q.top();
            q.pop();
            ans+=top1.second;
            ans+=top2.second;
            top1.first-=1;
            top2.first-=1;
            if(top1.first>0)
            {
                q.push(make_pair(top1.first,top1.second));
            }
            if(top2.first>0)
            {
                q.push(make_pair(top2.first,top2.second));
            }
        }
        if(!q.empty())
        {
            if(q.top().first>1)
            {
                return "";
            }
            else
            {
                return ans+=q.top().second;
            }
        }
        return ans;
    }
};