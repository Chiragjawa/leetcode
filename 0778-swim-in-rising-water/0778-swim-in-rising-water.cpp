class Solution {
    bool dfs(int i, int j, int n, vector<vector<int>>& grid, vector<vector<int>>& vis, int T) {
        if(i == n-1 && j == n-1) return true;

        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, -1, 0, 1};
        vis[i][j] = 1;

        for(int k=0; k<4; k++){
            int newr = i + delrow[k];
            int newc = j + delcol[k];
            if(newr>=0 && newc>=0 && newr<n && newc<n 
               && vis[newr][newc]==-1 && grid[newr][newc] <= T){
                if(dfs(newr, newc, n, grid, vis, T)) return true;
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0, high = n*n - 1;

        while(low < high){
            int mid = low + (high - low)/2;
            vector<vector<int>> vis(n, vector<int>(n, -1));

            if(grid[0][0] <= mid && dfs(0, 0, n, grid, vis, mid)){
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
