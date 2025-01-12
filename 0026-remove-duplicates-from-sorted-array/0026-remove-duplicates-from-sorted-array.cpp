class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count =1;
        int num =nums[0];
        int index =0;
        for(int i=0;i<nums.size();i++){
            if(num < nums[i]){
                count++;
                nums[index+1]=nums[i];
                num=nums[i];
                index++;
            }
        }
        return count;
    }
};