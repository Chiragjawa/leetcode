class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;
        for (int i = 2; i < n; i++) {             
            for (int j = 0; j < i; j++) {         
                for (int k = j + 1; k < i; k++) { 
                    if (nums[j] + nums[k] > nums[i]) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};