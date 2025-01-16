class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x1 = 0, x2 = 0;

        // XOR all elements of nums1
        for (int num : nums1) {
            x1 ^= num;
        }

        // XOR all elements of nums2
        for (int num : nums2) {
            x2 ^= num;
        }

        // Return the result based on the array sizes
        if (nums1.size() % 2 == 0 && nums2.size() % 2 == 0) {
            return 0;
        } else if (nums1.size() % 2 == 0) {
            return x2; // nums2 contributes to the result
        } else if (nums2.size() % 2 == 0) {
            return x1; // nums1 contributes to the result
        }

        // Both sizes are odd
        return x1 ^ x2;
    }
};
