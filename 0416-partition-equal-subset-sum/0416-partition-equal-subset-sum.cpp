class Solution {
private:
    bool func(int n , int target , vector<int> &nums , vector<vector<int>> &dp) {
        if(target == 0) return true;
        if(n == 0) return (nums[0]== target);
        if(dp[n][target] !=-1) return dp[n][target];
        bool nottake = func(n-1, target , nums ,dp);
        bool take = false;
        if(nums[n] <= target){
            take = func(n-1 , target-nums[n], nums, dp);
        }
        return dp[n][target] = take | nottake;
    } 
public:
    bool canPartition(vector<int>& nums) {
        int totalsum =0;
        int n =nums.size();
        for(int i=0 ;i<n;i++){
            totalsum+=nums[i];
        }
        if(totalsum % 2 != 0) return false;
        int target = totalsum/2;
        vector<vector<int>> dp(n ,vector<int>(target+1,-1));

        return func(n-1, target , nums , dp);
    }
};