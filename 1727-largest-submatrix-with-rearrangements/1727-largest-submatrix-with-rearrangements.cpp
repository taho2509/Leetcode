class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int j = 0; j < m; ++j) {
            for(int i = 0; i < n; ++i) {
                if(i > 0) {
                    if(matrix[i][j] != 0) matrix[i][j] += matrix[i - 1][j];
                }
            }
        }
        
        for(int i = 0; i < n; ++i) {
            sort(matrix[i].rbegin(), matrix[i].rend());
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int h = matrix[i][0];
            for(int j = 0; j < m; ++j) {
                h = min(h, matrix[i][j]);
                ans = max(ans, h*(j + 1));
            }
        }
        
        return ans;
    }
};