class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int number=0;
        for(int i=0;i<nums.size();i++){
            if(count ==0){
                number = nums[i];
                count++;
            }
            else if(number == nums[i]){
                count++;
            }
            else {
                count--;
            }
        }
        return number;
    }
};