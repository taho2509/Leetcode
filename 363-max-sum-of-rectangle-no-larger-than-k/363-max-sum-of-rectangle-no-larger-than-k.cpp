class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int r) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> accum(n, vector<int>(m + 1, 0));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                accum[i][j + 1] = accum[i][j] + matrix[i][j];
            }
        }
        
        int ans = INT_MIN;
        for(int i = 0; i < m; ++i) {
            for(int j = i + 1; j <= m; ++j) {
                set<int> pre = {0};
                int prefixSum = 0;
                
                for(int k = 0; k < n; ++k) {
                    int sum = accum[k][j] - accum[k][i];
                    prefixSum += sum;
                    auto it = pre.lower_bound(prefixSum - r);
                    if(it != pre.end()) ans = max(ans, prefixSum - (*it));
                    pre.insert(prefixSum);
                }
            }
        }
        
        return ans;
    }
};