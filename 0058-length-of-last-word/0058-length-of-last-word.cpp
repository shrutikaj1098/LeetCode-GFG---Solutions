class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        int i=0;
        while(s[i]==' ')
        {
            i++;
        }
        int val=0;
        while(i<s.length() && s[i]!=' ' )
        {
            i++;
            val++;
        }
        return val;
    }
};