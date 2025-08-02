class Solution {
private: 
    // int func(int i, int j, string text1, string text2 ,vector<vector<int>>& dp){
    //     if(i<0 || j<0) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(text1[i] == text2[j]){
    //         return 1+ func(i-1, j-1, text1, text2, dp);
    //     }

    //     return max(func(i-1, j, text1, text2, dp),func(i, j-1, text1, text2, dp));
    // }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max( dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[m][n];
        
    }
};