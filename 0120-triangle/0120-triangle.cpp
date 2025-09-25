class Solution {
private:
    // int func(int i , int j , vector<vector<int>>& triangle , vector<vector<int>>&dp){
    //     if(i== triangle.size()){
    //         return triangle[i][j];
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
        
    //         int first = func(i+1 , j , triangle ,dp);
    //         int second = func(i+1 , j+1 , triangle ,dp);
        

    //     return dp[i][j] = min(first, second) + triangle[i][j];
    // }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>>dp(m, vector<int>(m,-1));
        for(int i =0 ;i<triangle.size();i++){
            dp[m-1][i] = triangle[m-1][i];
        }
        for(int i =m-2 ;i>=0 ;i--){
            for(int j = i; j >= 0; j--) {
				int up = triangle[i][j] + dp[i+1][j];
				int up_left = triangle[i][j] + dp[i+1][j+1];
				dp[i][j] = min(up, up_left);
			}
        }
        return dp[0][0];
      
    }
};