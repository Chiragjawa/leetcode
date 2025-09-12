class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxend=0;
        int maxi =INT_MIN;
        for(int num :nums){
            maxend = max(num , maxend+num);
            maxi = max(maxi, maxend);
        }
        return maxi;
    }
};