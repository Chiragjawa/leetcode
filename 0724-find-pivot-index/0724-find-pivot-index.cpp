class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0;
        for(int num : nums){
            total +=num;
        }
        int leftsum=0;
        for(int i = 0; i < nums.size(); ++i){
            leftsum += nums[i];
            int rightsum = total - leftsum+nums[i];
            if(leftsum == rightsum) return i;
        }
        return -1;
    }
};