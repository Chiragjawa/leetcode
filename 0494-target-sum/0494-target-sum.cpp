class Solution {
private:
    int func(int i, int sum, vector<int>& nums, int target, vector<vector<int>>& dp, int offset) {
        if (i < 0) return (sum == target) ? 1 : 0;

        if (dp[i][sum + offset] != -1) return dp[i][sum + offset];

        int add = func(i - 1, sum + nums[i], nums, target, dp, offset);
        int sub = func(i - 1, sum - nums[i], nums, target, dp, offset);

        return dp[i][sum + offset] = add + sub;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for (int num : nums) totalSum += abs(num);

        // Shift all sum values by totalSum to handle negative sums
        int offset = totalSum;
        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, -1));

        return func(n - 1, 0, nums, target, dp, offset);
    }
};
