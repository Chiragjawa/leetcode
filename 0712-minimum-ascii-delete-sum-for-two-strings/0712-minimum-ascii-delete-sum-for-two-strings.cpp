class Solution {
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>>& dp) {
        if (i >= s1.size() && j >= s2.size()) return 0;

        if (i >= s1.size()) {
            int sum = 0;
            for (int k = j; k < s2.size(); k++)
                sum += (int)s2[k];
            return sum;
        }

        if (j >= s2.size()) {
            int sum = 0;
            for (int k = i; k < s1.size(); k++)
                sum += (int)s1[k];
            return sum;
        }

        if (dp[i][j] != -1) return dp[i][j];

        int ans;
        if (s1[i] == s2[j]) {
            ans = solve(i + 1, j + 1, s1, s2, dp);
        } else {
            int del1 = solve(i + 1, j, s1, s2, dp) + (int)s1[i];
            int del2 = solve(i, j + 1, s1, s2, dp) + (int)s2[j];
            ans = min(del1, del2);
        }

        return dp[i][j] = ans;
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, s1, s2, dp);
    }
};
