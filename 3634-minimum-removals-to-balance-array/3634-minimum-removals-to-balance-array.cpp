class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        if(nums.size() == 1) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < n; right++) {
            while(nums[right] > (long long) nums[left] * k) {
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }

        return n - maxLen;
    }
};