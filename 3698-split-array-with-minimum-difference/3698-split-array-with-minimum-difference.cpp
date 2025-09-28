class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n+1, 0);
        for(int i=0; i<n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }
        vector<bool> inc_prefix(n, true);
        for(int i=1; i<n; i++) {
            inc_prefix[i] = inc_prefix[i-1] && (nums[i-1] < nums[i]);
        }
        vector<bool> dec_suffix(n, true);
        for(int i=n-2; i>=0; i--) {
            dec_suffix[i] = dec_suffix[i+1] && (nums[i] > nums[i+1]);
        }
        long long ans = LLONG_MAX;
        for(int j=1; j<n; j++) {
            if(inc_prefix[j-1] && dec_suffix[j]) {
                long long left_sum  = prefix[j];
                long long right_sum = prefix[n] - prefix[j];
                long long diff = llabs(left_sum - right_sum);
                ans = min(ans, diff);
            }
        }

        return (ans == LLONG_MAX ? -1 : ans);
    }
};
