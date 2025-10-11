class Solution {
    long long helper(int i, vector<int>& vals,
                     unordered_map<int, long long>& sum,
                     vector<long long>& dp) {
        if (i >= vals.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        long long skip = helper(i + 1, vals, sum, dp);

        int j = i + 1;
        while (j < vals.size() && vals[j] <= vals[i] + 2)
            j++;

        long long take = sum[vals[i]] + helper(j, vals, sum, dp);

        return dp[i] = max(skip, take);
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
         unordered_map<int, long long> sum;
        for (int x : power) sum[x] += x;

        vector<int> vals;
        for (auto& p : sum) vals.push_back(p.first);
        sort(vals.begin(), vals.end());

        vector<long long> dp(vals.size(), -1);
        return helper(0, vals, sum, dp);
    }
};