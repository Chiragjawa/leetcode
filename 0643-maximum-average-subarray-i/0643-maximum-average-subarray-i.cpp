class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = accumulate(nums.begin(), nums.begin() + k, 0.0);
        double maxi = sum;  

        int j = 0;
        for (int i = k; i < n; i++) {
            sum -= nums[j];   
            sum += nums[i];   
            j++;
            maxi = max(maxi, sum);
        }

        return maxi / k;
    }
};
