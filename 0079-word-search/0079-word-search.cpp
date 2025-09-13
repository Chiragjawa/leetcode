class Solution {
private:
    int n , m;
    bool func(int i, int j, int len, vector<vector<char>>& board, string word){
       if (len == word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[len]) 
            return false;

        char temp = board[i][j];
        board[i][j] = '#';
        int dir[] ={1,0,-1,0};
        int dic[] ={0,1,0,-1};

        for(int a=0;a<4;a++){
            int nrow = i+dir[a];
            int ncol = j+dic[a];

            if(func(nrow,ncol, len+1, board,word)){
                return true;
            }
        }
        board[i][j] =temp;
        return false;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
         m = board.size();
         n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j]==word[0] && func(i, j, 0 , board,word)) {
                    return true;
                }
            }
        }
        return false;
    }
};