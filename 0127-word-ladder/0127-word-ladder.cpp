class Solution {
public:
    int bfs(string beginWord, string endWord, vector<string>& wordList)
    {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        while(!q.empty())
        {
            string str=q.front().first;
            int step=q.front().second;
            q.pop();
            if(str==endWord)return step;
            for(int i=0;i<str.length();i++)
            {
                char original=str[i];
                for(auto j='a';j<='z';j++)
                {
                    str[i]=j;
                    if(s.find(str)!=s.end())
                    {
                        q.push({str,step+1});
                        s.erase(str);
                    }
                }
                str[i]=original;

            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return bfs(beginWord,endWord,wordList);
    }
};