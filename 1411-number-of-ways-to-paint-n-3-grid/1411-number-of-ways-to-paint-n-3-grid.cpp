class Solution {
public:
    int M = 1e9 + 7;

    vector<string> states = {
        "RYR", "RYG", "RGR", "RGY",
        "YRY", "YRG", "YGR", "YGY",
        "GRY", "GRG", "GYR", "GYG"
    };

    vector<vector<int>> dp;

    int solve(int ind, int prevState) {
        if (ind == 0) return 1;

        if (dp[ind][prevState] != -1)
            return dp[ind][prevState];

        int res = 0;
        string prev = states[prevState];

        for (int curr = 0; curr < 12; curr++) {
            if (curr == prevState) continue;

            bool conflict = false;
            string currState = states[curr];

            for (int i = 0; i < 3; i++) {
                if (prev[i] == currState[i]) {
                    conflict = true;
                    break;
                }
            }

            if (!conflict) {
                res = (res + solve(ind - 1, curr)) % M;
            }
        }

        return dp[ind][prevState] = res;
    }

    int numOfWays(int n) {
        dp.assign(n, vector<int>(12, -1));

        int result = 0;
        for (int i = 0; i < 12; i++) {
            result = (result + solve(n - 1, i)) % M;
        }

        return result;
    }
};
