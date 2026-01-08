class Solution {
public:
    int solve(int i, int j, vector<int>&nums1, vector<int>&nums2, vector<vector<int>>&dp){
        if(i >= nums1.size() || j>= nums2.size()) return 0;
        if(dp[i][j] !=-1) return dp[i][j];
        int take = solve(i+1,j+1,nums1, nums2, dp)+ nums1[i]*nums2[j];
        int nottake1 =solve(i+1,j,nums1 ,nums2 , dp);
        int nottake2 =solve(i,j+1,nums1 ,nums2 , dp);
        dp[i][j] = max({take,nottake1, nottake2});
        return dp[i][j];
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int maxi1=INT_MIN;
        int maxi2 = INT_MIN;
        int mini1 = INT_MAX;
        int mini2 = INT_MAX;
        int cnt1=0, cnt2=0;
        for(int i=0 ;i< nums1.size();i++){
            if(nums1[i] < 0) cnt1++;
            maxi1 = max(maxi1, nums1[i]);
            mini1 = min(mini1, nums1[i]);
        }
        for(int i=0 ;i< nums2.size();i++){
            if(nums2[i] < 0) cnt2++;
            maxi2 = max(maxi2, nums2[i]);
            mini2 = min(mini2, nums2[i]);
        }
        if(cnt1 == nums1.size() && cnt2==0) return maxi1*mini2;
        else if(cnt1 == 0 && cnt2==nums2.size()) return mini1*maxi2;
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return solve(0,0,nums1,nums2, dp);
    }
};