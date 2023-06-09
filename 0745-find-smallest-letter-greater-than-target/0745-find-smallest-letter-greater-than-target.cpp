class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char c='-';
        for(auto i: letters)
        {
            if(i>target)
            {
                c=i;
                break;
            }
        }
        if(c=='-')
        {
            return letters[0];
        }
        return c;
    }
};