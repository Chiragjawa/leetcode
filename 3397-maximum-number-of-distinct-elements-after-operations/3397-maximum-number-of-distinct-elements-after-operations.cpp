class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int ans =0;
        int prev= INT_MIN;
        for(int i=0;i<nums.size();i++){
            int l = max(nums[i]-k ,prev+1);
            if(l<=nums[i]+k){
                ans++;
                prev =l;
            }

        }

        return ans;
    }
};