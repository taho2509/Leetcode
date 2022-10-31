class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        
        for(int i = 0; i < m; ++i) {
            int element = matrix[0][i];
            for(int j = 0; j < n; ++j) {
                if(i + j >= m) break;
                if(matrix[j][i + j] != element) return false;
            }
        }
        
        for(int i = 0; i < n; ++i) {
            int element = matrix[i][0];
            for(int j = 0; j < m; ++j) {
                if(i + j >= n) break;
                if(matrix[i + j][j] != element) return false;
            }
        }
        
        return true;
    }
};