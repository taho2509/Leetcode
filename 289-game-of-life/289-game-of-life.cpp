class Solution {
    vector<int> mov{-1,-1,0,1,1,1,0,-1,-1,-1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> b2(n, vector<int>(m));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                fill(board, b2, i, j);
            }
        }
        
        board = b2;
    }
    
    void fill(vector<vector<int>>& orig, vector<vector<int>>& copy, int r, int c) {
        int n = orig.size();
        int m = orig[0].size();
        
        int count = 0;
        for(int i = 0; i < 8; ++i) {
            int nr = r + mov[i], nc = c + mov[i + 2];
            if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if(orig[nr][nc] == 1) ++count;
        }
        
        if(orig[r][c] == 1) {
            if(count < 2) copy[r][c] = 0;
            else if(count > 3) copy[r][c] = 0;
            else copy[r][c] = 1;
        } else {
            if(count == 3) copy[r][c] = 1;
        }
    }
};