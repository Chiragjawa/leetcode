class Solution {
    private:
    int paths(int m, int n ,int i ,int j , vector<vector<int>>& dp){
        if (i >= m || j >= n) return 0;

        // Reached destination
        if (i == m - 1 && j == n - 1) return 1;

        // Return cached result
        if (dp[i][j] != -1) return dp[i][j];

        // Store result: move down and right
        dp[i][j] = paths(m, n, i + 1, j, dp) + paths(m, n, i, j + 1, dp);
        return dp[i][j];

    }
public:
    int uniquePaths(int m, int n) {
  vector<vector<int>> dp(m, vector<int>(n, -1));
      return paths(m , n , 0,0 ,dp);
    
    }
};