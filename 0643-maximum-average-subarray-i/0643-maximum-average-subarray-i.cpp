class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        int j=k-1;
        double maxi = INT_MIN;
        double sum = accumulate(nums.begin(), nums.begin() + k, 0);
        while(j<nums.size()){
            double avg = (double)sum / k;
            maxi = max(maxi,avg);
            sum -= nums[i];
            i++;
            j++;
            if (j >= nums.size()) break;
            sum += nums[j];
            
        }
        return maxi;

    }
};