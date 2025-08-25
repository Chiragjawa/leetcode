class Solution {
private:
int func(vector<int>& prices, int ind ,int buy, vector<vector<int>>&dp){
    if(ind == prices.size()){
        return 0;
    }
    if(dp[ind][buy] != -1){
        return dp[ind][buy];
    }
    int profit =0;
    if(buy == 0){
        profit = max(0+func(prices,ind+1,0,dp) , -prices[ind]+func(prices,ind+1,1,dp));
    }
    if(buy == 1){
        profit = max(0+func(prices,ind+1,1,dp) , prices[ind]+func(prices,ind+1,0,dp));
    }

    return dp[ind][buy] = profit;
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));

        if(n ==0) return 0;

        return func(prices ,0,0,dp);   
    }
};