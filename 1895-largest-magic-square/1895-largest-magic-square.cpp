class Solution {
    private:
    bool isvalid(vector<vector<int>>& grid , int i ,int j, int k){
        int sum =0;
        for(int a =i ;a<=i+k; a++){
            int s =0;
            for(int b =j; b<=j+k ;b++){
                s = s+grid[a][b];
            }
            if(a==i) sum =s;
            else if(s!= sum) return false;
        }
        for(int a =j ;a<=j+k; a++){
            int s =0;
            for(int b =i; b<=i+k ;b++){
                s = s+grid[b][a];
            }
            if(s!= sum) return false;
        }
        int s=0;
        for(int d = 0 ;d<=k ;d++) s = s+ grid[i+d][j+d];
        if(sum != s) return false;

        s=0;
        for(int d =0 ;d<=k ;d++) s+= grid[i+d][j+k-d];
        if(sum != s) return false;

        return true; 

    }

public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=1;
        for (int k = 1; k < min(n, m); k++) {
            for (int i = 0; i+k < n; i++) {
                for (int j = 0; j+k < m; j++) {
                   if(isvalid(grid, i, j, k)) ans =k+1;
                }
            }
        }
        return ans;
    }
};