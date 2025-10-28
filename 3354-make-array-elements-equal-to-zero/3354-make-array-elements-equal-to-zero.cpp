class Solution {
    int isvalid(int idx , vector<int>nums){
        int leftsum =0;
        for(int i=0 ;i<idx ;i++){
            leftsum += nums[i];
        }    
        int rightsum =0;
        for(int i=idx+1 ;i<nums.size();i++){
            rightsum+= nums[i];
        }
        if(leftsum == rightsum){
            return 2;
        }
        if(leftsum == rightsum-1 || rightsum == leftsum-1) return 1;
        return 0;
    }
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt+= isvalid(i, nums);
            }
        }
        return cnt;
    }
};