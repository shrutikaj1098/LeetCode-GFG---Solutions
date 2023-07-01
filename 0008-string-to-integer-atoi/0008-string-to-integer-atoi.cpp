class Solution {
public:
long convert(string str, int i, long int s, int sign)
    {
        if(s*sign >=INT_MAX) return INT_MAX;
        if(s*sign<=INT_MIN) return INT_MIN;
        if(i>=str.size() || str[i]<'0' || str[i]>'9' )
        {
            return sign*s;
        }
        
            s = s*10 +(str[i]-'0');
            return convert(str,i+1,s,sign);
            
        
        
        
    }
    int myAtoi(string str) {
         
        
        int i = 0, n = str.size(), sign = 1;
        while (i < n && str[i] == ' '){
            ++i;
        }
        if (str[i] == '-')
            sign = -1, ++i;
        else if (str[i] == '+')
            ++i;
        return convert(str, i, 0,sign);
        
    }
};