class Solution {
public:

    bool dayssaisfybookay(vector<int> &bloomDay, int M, int K, long long mid)
    {
        long long totalbookaymade=0, counter=0;
        for(long long i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=mid) counter++;
            else
            {
                counter=0;
            }
            if(counter==K)
            {
                totalbookaymade++;
                counter=0;
            }
             if(totalbookaymade>=M) return true;
            
        }
        
       
        return false;
    }
    int minDays(vector<int>& bloomDay, int M, int K) {
      if((long long)M*K > bloomDay.size()) return -1;
      long long s=1,e=*max_element(bloomDay.begin(),bloomDay.end()),result=-1;
      while(s<=e)
      {
          long long mid=s+(e-s)/2;
          if(dayssaisfybookay(bloomDay, M, K, mid))
          {
              result=mid;
              e=mid-1;
          }
          else
          {
              s=mid+1;
          }
      }
      return result;
    }
};