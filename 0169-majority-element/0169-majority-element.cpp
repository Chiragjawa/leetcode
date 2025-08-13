class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()==1){
           return nums[0];
       }
        int compare = nums.size()/2;
        int cnt =1;
        int answer = 0;
        for(int i=0 ;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                cnt++;
                if(cnt>compare){
                    answer = nums[i];
                }
            }
            else{
                cnt =1;
            }

        }
        return answer;
    }   
};