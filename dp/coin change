class Solution {
private:
    int func(int n, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (n == 0) {
            return (amount % coins[0] == 0) ? (amount / coins[0]) : INT_MAX;
        }

        if (dp[n][amount] != -1) return dp[n][amount];

        int nottake = func(n - 1, coins, amount, dp);
        int take = INT_MAX;
        if (coins[n] <= amount) {
            int res = func(n, coins, amount - coins[n], dp);
            if (res != INT_MAX) take = 1 + res;
        }

        return dp[n][amount] = min(take, nottake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = func(n - 1, coins, amount, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
