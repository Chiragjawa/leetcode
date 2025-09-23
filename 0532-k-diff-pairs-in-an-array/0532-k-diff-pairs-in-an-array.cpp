class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        int ans = 0;
        for (int num : nums) {
            if (k == 0) {
                if (mp[num] > 1) {
                    ans++;
                    mp[num] = 0;
                }
            } else if (mp.find(num + k) != mp.end()) {
                if (mp[num + k] > 0) {
                    ans++;
                    mp[num + k]=0;
                }
            }
        }
        return ans;
    }
};