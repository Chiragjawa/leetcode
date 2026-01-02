class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid =(nums.size()-1)/2;
        if(nums[0] == nums[mid]) return nums[mid];
        return nums[mid +1];
    }
};