class Solution {
public:
    void addre(string &num1, string &num2, int p1, int p2, int carry,string &ans)
    {
        if(p1<0 && p2<0)
        {
            if(carry!=0)
            {
                ans.push_back(carry+'0');
                return;
            }
            return;
        }
        int ans1=(p1>=0? num1[p1]:'0')-'0';
        int ans2=(p2>=0? num2[p2]:'0')-'0';
        int total=ans1+ans2+carry;
        int digit=total%10;
        carry=total/10;
        // cout<<carry<<endl;
        ans.push_back(digit+'0');
        addre(num1,num2,p1-1,p2-1,carry,ans);
        return;
    }
    string addStrings(string num1, string num2) {
        string ans="";
        int p1=num1.size()-1;
        int p2=num2.size()-1;
        addre(num1,num2,p1,p2,0,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};