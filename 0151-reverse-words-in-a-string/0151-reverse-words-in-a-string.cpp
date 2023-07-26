class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        int n=s.size();
        int i=0;
        while(i<s.size())
        {
            if(s[i]==' ')
            {
                i++;
            }
            else
            {
                string h="";
                while(s[i]!=' ' && i<n)
                {
                    h+=s[i];
                    i++;
                }
                v.push_back(h);
            }
        }
        reverse(v.begin(),v.end());
        string ans="";
        for(auto i:v)
        {
            ans+=i;
            ans+=' ';
        }
        ans.pop_back();
        return ans;;
    }
};