class Solution {
private:
    // int func(int i ,int j, string s,vector<vector<int>>&dp ){
    //      if (i > j) return 0;
    //     if (i == j) return 1;
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     if(s[i] == s[j]){
    //         return dp[i][j]= 2+func(i+1 ,j-1 , s, dp);
    //     }
    //     return dp[i][j] = max(func(i+1 ,j , s, dp) , func(i,j-1 ,s,dp));
    // }
public:

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }


};