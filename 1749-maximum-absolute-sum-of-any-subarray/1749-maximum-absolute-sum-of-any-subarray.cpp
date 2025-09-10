class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxend=0;
        int maxi =0;
        int minend =0;
        int mini =0;
        for(int i=0; i<nums.size();i++){
            maxend = max(nums[i] , maxend+nums[i]);
            maxi = max(maxi , maxend);
            minend = min(nums[i], minend+nums[i]);
            mini = min(mini, minend);
        }
        return max(abs(maxi),abs(mini));
    }
};