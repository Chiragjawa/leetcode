class Solution {
private:
    int func(int n, int prev, vector<int>&nums, vector<vector<int>>&dp){
        if(n>=nums.size()) return 0;

        if(dp[n][prev+1]!=-1) return dp[n][prev+1];

        int nottake = 0+func(n+1,prev, nums,dp);
        int take =0;
        if(prev==-1 || nums[prev]<nums[n]){
             take += 1+func(n+1,n, nums,dp);
        }
        
        return dp[n][prev+1] = max(nottake , take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
     int n = nums.size();
     int prev =-1;
     vector<vector<int>>dp(n,vector<int>(n+1,-1));

     return func(0, prev , nums, dp);   
    }
};