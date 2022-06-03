class NumMatrix {
    vector<vector<int>> SUM;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        SUM = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 0; i < n; ++i) {
            int row = 0;
            for(int j = 0; j < m; ++j) {
                row += matrix[i][j];
                SUM[i + 1][j + 1] = SUM[i][j + 1];
                SUM[i + 1][j + 1] += row;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return SUM[row2 + 1][col2 + 1] - SUM[row2 + 1][col1] - SUM[row1][col2 + 1] + SUM[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */