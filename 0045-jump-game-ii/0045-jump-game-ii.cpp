class Solution {
public:
    int jump(vector<int>& nums) {
      int jump=0;
      int l=0;
      int r=0;
      int n=nums.size();
      while ( r< n-1){
        int fatherest =0;
        for(int i=l;i<=r;i++){
            fatherest = max(i+ nums[i] , fatherest);
        }
        l= r+1;
        r=fatherest;
        jump = jump +1;
      }
      return jump;
    }
};