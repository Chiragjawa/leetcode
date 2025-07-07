class Solution {
public:
    int atmostkdis(vector<int>& nums, int k){
        int l=0,r=0,nodis=0,count=0;
        vector<int> att(nums.size()+1,-1);
        while(r<nums.size()){
            if(att[nums[r]]==-1){
                nodis+=1;
            }
            att[nums[r]]=r;
            while(nodis>k){
                if(att[nums[l]]==l){
                    nodis-=1;
                    att[nums[l]]=-1;
                }
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostkdis(nums,k)-atmostkdis(nums,k-1);
    }
};