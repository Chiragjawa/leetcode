class Solution {
public:
    void dfs(vector<vector<int>>& heights,vector<vector<int>>& vis , int row ,int col ){
        vis[row][col]=1;
        int n= heights.size();
        int m= heights[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        for(int i=0;i<4 ;i++){
            int newrow = row+delrow[i];
            int newcol = col+delcol[i];
            if(newrow >=0 && newrow<n && newcol>=0 && newcol < m && !vis[newrow][newcol] && heights[newrow][newcol]>=heights[row][col]){
                dfs(heights ,vis, newrow,newcol);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        int n=heights.size();
        int m = heights[0].size();
        vector<vector<int>> atl(n, vector<int>(m,0));
        vector<vector<int>> pac(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            dfs(heights , atl , i,m-1);
            dfs(heights , pac , i,0);
        }
        for(int j=0; j<m ;j++){
            dfs(heights , pac , 0 ,j);
            dfs(heights , atl , n-1 ,j);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};