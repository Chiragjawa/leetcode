class Solution {
private:
    // int func(int i,int j ,int m, int n, vector<vector<int>>& matrix, vector<vector<int>>&dp){
    //     if(i<0 || j<0 || i>m-1 || j>n-1){
    //         return INT_MAX;
    //     }
    //     if(i==m-1) return matrix[i][j];
    //     if(dp[i][j] != -1 ) return dp[i][j];
    
    //     int first = func(i+1 , j-1 ,m,n,matrix,dp);
    //     int second = func(i+1 , j ,m,n,matrix,dp);
    //     int third = func(i+1 , j+1 ,m,n,matrix,dp);
    //     dp[i][j] = min(min(first,second),third)+ matrix[i][j];
    //     return dp[i][j];
    // }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        for(int i =0 ;i<m;i++){
            dp[m-1][i] = matrix[m-1][i];
        }
        int ans = INT_MAX;

        for(int i=m-2;i>=0;i--){
            for(int j= 0 ;j<n ;j++){

              int down = dp[i + 1][j];
                int left = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
                int right = (j < n - 1) ? dp[i + 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({left, down, right});
            }

        }
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[0][j]);
        }
        return ans;
    }
};