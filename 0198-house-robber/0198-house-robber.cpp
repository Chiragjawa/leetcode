class Solution {
private:
    // int func(int ind , vector<int> nums ,vector<int>& dp){
    //     if(ind == 0)return nums[ind];
    //     if(ind <0 )return 0;
    //     if(dp[ind] !=-1) return dp[ind];
    //     int pick = nums[ind] + func(ind-2 ,nums,dp);
    //     int notpick = 0+ func(ind -1 ,nums ,dp);

    //     return dp[ind] = max (pick ,notpick);
    // }
public:
    int rob(vector<int>& nums) {
      int n= nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
    vector<int> dp(n+1 ,-1);
    
    // return func(n-1 , nums ,dp);
        dp[0] = nums[0];
        for(int i=1 ;i<nums.size() ;i++){
             int pick = nums[i] ;
             if(i>1) pick+= dp[i-2];
             int notpick = 0+ dp[i-1];
             dp[i] = max(pick ,notpick);
             
        }
        return dp[n-1];
    }
};