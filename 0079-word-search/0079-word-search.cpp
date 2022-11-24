class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, visited, word, i, j, 0)) return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string &word, int si, int sj, int index) {
        if(index >= word.size()) return true;
        
        int n = board.size();
        int m = board[0].size();
        
        if(si < 0 || si >= n) return false;
        if(sj < 0 || sj >= m) return false;
        
        if(visited[si][sj]) return false;
        if(word[index] != board[si][sj]) return false;
        
        visited[si][sj] = true;
        if(dfs(board, visited, word, si + 1, sj, index + 1)) return true;
        if(dfs(board, visited, word, si - 1, sj, index + 1)) return true;
        if(dfs(board, visited, word, si, sj + 1, index + 1)) return true;
        if(dfs(board, visited, word, si, sj - 1, index + 1)) return true;
        visited[si][sj] = false;
        return false;
    }
};