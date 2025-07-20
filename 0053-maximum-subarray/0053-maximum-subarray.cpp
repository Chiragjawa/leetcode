class Solution {
private:
    void fast(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int sumi(vector<int>& nums, int left, int mid, int right){
        int lefty=INT_MIN, sum=0;
        for(int i=mid;i>=left;i--){
            sum+=nums[i];
            lefty=max(sum, lefty);
        }
        int righty=INT_MIN;
        sum=0;
        for(int i=mid+1;i<=right;i++){
            sum+=nums[i];
            righty=max(sum, righty);
        }
        return lefty+righty;
    }
    int midw(vector<int>& nums, int left, int right){
        if(left==right){
            return nums[left];
        }
        int mid=(left+right)/2;
        int maxl=midw(nums, left, mid);
        int maxr=midw(nums, mid+1, right);
        int sum=sumi(nums, left, mid, right);
        return max({maxl, maxr, sum});
    }
public:
    int maxSubArray(vector<int>& nums) {
        fast();
        int left=0, right=nums.size()-1;
        return midw(nums, left, right);
    }
};