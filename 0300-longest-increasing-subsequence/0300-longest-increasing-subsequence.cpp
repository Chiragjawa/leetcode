class Solution {
private:
    // int func(int n, int prev, vector<int>&nums, vector<vector<int>>&dp){
    //     if(n>=nums.size()) return 0;

    //     if(dp[n][prev+1]!=-1) return dp[n][prev+1];

    //     int nottake = 0+func(n+1,prev, nums,dp);
    //     int take =0;
    //     if(prev==-1 || nums[prev]<nums[n]){
    //          take += 1+func(n+1,n, nums,dp);
    //     }

    //     return dp[n][prev+1] = max(nottake , take);
    // }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev = ind - 1; prev >= -1; prev--) {
                int len = dp[ind + 1][prev + 1];

                if (prev == -1 || nums[prev] < nums[ind]) {
                    len = max(len, 1 + dp[ind + 1][ind + 1]);
                }

                dp[ind][prev + 1] = len; 
            }
        }
        return dp[0][0];
    }
};