class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)!=string::npos )
        {
            if(s.find(part))
            {
               
                s.erase(s.find(part),part.size());
                cout<<s<<endl;
            }
            else if(s.find(part)!=string::npos && s.size()>=part.size())
            {
                s.erase(s.find(part),part.size());
                
            }
            
        }
        return s;
    }
};