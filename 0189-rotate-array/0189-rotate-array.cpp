class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= k % nums.size();
        vector<int> a(nums.end()-n, nums.end());
         for(int i=nums.size()-n-1;i>=0;i--){
           nums[i+n]=nums[i];
        }

        for(int i=0;i<n;i++){
            nums[i]=a[i];
        }
    }
};