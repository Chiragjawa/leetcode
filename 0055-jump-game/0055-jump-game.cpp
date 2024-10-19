#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input vector
        int reachable = 0;   // Variable to track the farthest reachable index
        
        // Iterate through each element in the vector
        for (int i = 0; i < n; i++) {
            if (i > reachable) {
                // If the current index is beyond the farthest reachable index, we can't proceed
                return false;
            }
            // Update the farthest reachable index
            reachable = max(reachable, i + nums[i]);
        }
        
        // If we can reach or pass the last index, return true
        return true;
    }
};
