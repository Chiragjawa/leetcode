class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int cnt =1;
        for(int i=2;i<n;i++){
            for(int j=0 ;j<i-1;j++){
                if(nums[j]+nums[j+1] > nums[i]){
                    cnt+=1;
                }
            }
        }
        return cnt;
    }
};