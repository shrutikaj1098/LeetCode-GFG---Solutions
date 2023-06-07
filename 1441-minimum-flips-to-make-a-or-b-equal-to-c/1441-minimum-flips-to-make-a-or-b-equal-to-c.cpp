class Solution {
public:
    void converttobinary(vector<int>&v, int num)
    {
        while(num)
        {
            v.push_back(num%2);
            // cout<<(v.back());
            num=num/2;
        }
        
        // for(auto i: v)
        // {
        //     cout<<i <<endl;
        // }
    }
    int minFlips(int a, int b, int c) {
        vector<int>binarya,binaryb,binaryc;
        converttobinary(binarya, a);
        converttobinary(binaryb, b);
        converttobinary(binaryc, c);
        int maxi=max(binarya.size(),max(binaryb.size(),binaryc.size()));
        if(maxi>binarya.size())
        {
            while(binarya.size()!=maxi)
            {
                binarya.push_back(0);
            }
        }
        if(maxi>binaryb.size())
        {
            while(binaryb.size()!=maxi)
            {
                binaryb.push_back(0);
            }
        }
        if(maxi>binaryc.size())
        {
            while(binaryc.size()!=maxi)
            {
                binaryc.push_back(0);
            }
        }
        reverse(binarya.begin(),binarya.end());
        reverse(binaryb.begin(),binaryb.end());
        reverse(binaryc.begin(),binaryc.end());
        int flips=0;
        for(int i=0;i<binaryc.size();i++)
        { 
            cout<<binarya[i]<<" "<<binaryb[i]<<" "<<binaryc[i]<<endl;
            if((binarya[i] or binaryb[i])!=binaryc[i])
            {
                if(binarya[i]==1 && binaryb[i]==1 && binaryc[i]==0)
                {
                    flips+=2;
                }
                else
                {
                    flips++;
                }
            }
        }
        return flips;
    }
};