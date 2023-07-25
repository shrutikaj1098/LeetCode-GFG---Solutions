class Solution {
public:

int getAns(vector<int>& Arr, int n, int ind, int buy, vector<vector<int>>& dp ){

    if(ind>=n) return 0; //base case
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        
    int profit;
    
    if(buy==0){// We can buy the stock
        profit = max(0+getAns(Arr,n,ind+1,0,dp), 
                    -Arr[ind] + getAns(Arr,n,ind+1,1,dp));
    }
    
    if(buy==1){// We can sell the stock
        profit = max(0+getAns(Arr,n,ind+1,1,dp),
                    Arr[ind] + getAns(Arr,n,ind+2,0,dp));
    }
    
    return dp[ind][buy] = profit;
}

    int maxProfit(vector<int>& prices) {
           int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
    
    return getAns(prices,n,0,0,dp);
    }
};