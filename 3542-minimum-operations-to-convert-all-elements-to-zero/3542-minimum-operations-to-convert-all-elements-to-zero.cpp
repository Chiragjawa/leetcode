class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int>st(nums.size()+1, 0);
        int ans =0;
        int top=0;
        for(int num:nums){
            while(st[top]>num){
                top--;
                ans++;
            }
            if(st[top] != num){
                st[++top] = num;
            }
        }
        return ans+top;
    }
};