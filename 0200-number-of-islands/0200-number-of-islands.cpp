class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& grid){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n= grid.size();
        int m= grid[0].size();
        while(!q.empty()){
            int row= q.front().first;
            int col = q.front().second;
            q.pop();
            for(int delrow =-1 ;delrow<=1;delrow++){
                    int nrow = row+delrow;
                    int ncol = col;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    
                }
            }            
            for(int delcol =-1 ;delcol<=1;delcol++){
                    int nrow = row;
                    int ncol = col+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    
                }
            }            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col = grid[0].size();
        vector<vector<int>>vis(row,vector<int>(col,0));
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;  
                    bfs(i, j ,vis, grid);
                }
            }
        }
        return count;
    }
};