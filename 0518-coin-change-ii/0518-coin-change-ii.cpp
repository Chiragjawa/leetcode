class Solution {
private:
    // int func(int i , int amount , vector<int> coins , vector<vector<int>> &dp ){
    //     if(amount == 0) return 1;
    //     if(i==0) return amount % coins[0] == 0 ? 1 : 0;

    //     if(dp[i][amount] !=-1) return dp[i][amount];
    //     int nottake = func(i-1 , amount, coins, dp);
    //     int take = 0;
    //     if(amount>= coins[i]){
    //         take = func(i, amount - coins[i] ,coins, dp);
    //     }
    //     return take+nottake;
    // }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1 ,0));
        for(int i=0;i<n;i++) {
            dp[i][0] == 1;
        }
        for(int t = 0; t <= amount; ++t) {
            if(t % coins[0] == 0)
                dp[0][t] = 1;
        }
        for(int i = 1; i < n; ++i) {
            for(int t = 0; t <= amount; ++t) {
                long long notTake = dp[i - 1][t];
                long long take = 0;
                if(t >= coins[i])
                    take = dp[i][t - coins[i]];
                dp[i][t] = take + notTake;
            }
        }

        return (int)dp[n - 1][amount];
    }
};