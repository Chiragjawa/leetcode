class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans(1<<n);
        int j=0;
        for(int mask =0;mask<(1<<n);mask++){
            for(int  i=0;i<n;i++){
                if(mask& (1<<i)){
                    ans[j].push_back(nums[i]);
                }
            }
            j++;
        }
        return ans;
    }
};