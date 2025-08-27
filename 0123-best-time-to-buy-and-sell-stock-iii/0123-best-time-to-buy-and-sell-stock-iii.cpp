class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[3][2][n];
        dp[1][0][0]=-prices[0];
        dp[2][0][0]=-prices[0];
        dp[1][1][0]=0;
        dp[2][1][0]=0;
        dp[0][0][0] = INT_MIN; 
        for(int i=1;i<n;i++)
        {
            dp[1][0][i] = max(dp[1][0][i-1], -prices[i]);
            dp[1][1][i] = max(dp[1][1][i-1], dp[1][0][i-1] + prices[i]);

            dp[2][0][i]=max(dp[2][0][i-1],dp[1][1][i-1]-prices[i]);
            dp[2][1][i]=max(dp[2][1][i-1],dp[2][0][i-1]+prices[i]);
        }
        return dp[2][1][n-1];
        
    }
};