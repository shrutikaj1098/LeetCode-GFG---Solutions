class Solution {
public:
    bool ispalindrom(string s,int start, int end)
    {
        while(start<=end)
        {
            if(s[start]!=s[end])
            {
                return false;
            }
            start++,end--;
        }
        return true;
    }
    void generatepalindrome(string s, vector<vector<string>>&v,vector<string>p,int index)
    {
        if(index==s.size())
        {
            v.push_back(p);
        }
        for(int i=index;i<s.size();i++)
        {
            if(ispalindrom(s,index,i))
            {
                p.push_back(s.substr(index,i-index+1));
                generatepalindrome(s,v,p,i+1);
                p.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>v;
        vector<string>p;
        // string op="";
        generatepalindrome(s,v,p,0);
        return v;
    }
};