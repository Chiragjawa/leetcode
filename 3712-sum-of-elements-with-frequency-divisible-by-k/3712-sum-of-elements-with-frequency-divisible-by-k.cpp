#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;

        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && nums[j] == nums[i]) {
                j++;
            }

            int cnt = j - i;  
            if (cnt % k == 0) {
                ans += nums[i] *cnt;
            }

            i = j;  
        }

        return ans;
    }
};
