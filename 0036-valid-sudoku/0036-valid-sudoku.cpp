class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            if(!checkRow(i, board)) return false;
            if(!checkColumn(i, board)) return false;
        }
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(!checkSquare(i * 3, j * 3,board)) return false;
            }
        }
        return true;
    }
    
    bool checkRow(int r, vector<vector<char>>& board) {
        vector<bool> marks(10,false);
        for(int i = 0; i < 9; i++) {
            if(board[r][i] != '.') {
                if(marks[board[r][i]]) return false;
                marks[board[r][i]] = true;
            }
        }
        return true;
    }
    
    bool checkColumn(int c, vector<vector<char>>& board) {
        vector<bool> marks(10,false);
        for(int i = 0; i < 9; i++) {
            if(board[i][c] != '.') {
                if(marks[board[i][c]]) return false;
                marks[board[i][c]] = true;
            }
        }
        return true;
    }
    
    bool checkSquare(int r, int c, vector<vector<char>>& board) {
        vector<bool> marks(10,false);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[r + i][c + j] != '.') {
                    if(marks[board[r + i][c + j]]) return false;
                    marks[board[r + i][c + j]] = true;
                }
            }
        }
        return true;
    }
};