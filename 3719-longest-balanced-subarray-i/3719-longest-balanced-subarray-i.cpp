class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> even;
        unordered_set<int> odd;
        int len = 0;
        for (int i = 0; i < n; i++) {
            even.clear();
            odd.clear();
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0)
                    even.insert(nums[j]);
                else
                    odd.insert(nums[j]);
                if (even.size() == odd.size()) {
                    int curr = j - i + 1;
                    len = max(len, curr);
                }
            }
        }
        return len;
    }
};