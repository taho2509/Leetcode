class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& M, int target) {
        int n = M.size();
        int m = M[0].size();
        vector<vector<int>> memo(n, vector<int>(m));
        
        for(int i = 0; i < n; ++i) {
            int t = 0;
            for(int j = 0; j < m; ++j) {
                t += M[i][j];
                memo[i][j] = t;
                if(i > 0) {
                    memo[i][j] += memo[i - 1][j];
                }
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int value = memo[i][j];
                for(int k = -1; k < i; ++k) {
                    for(int l = -1; l < j; ++l) {
                        int t = value;
                        if(k >= 0) {
                            t -= memo[k][j];
                        }
                        if(l >= 0) {
                            t -= memo[i][l];
                        }
                        if(k >= 0 && l >= 0) {
                            t += memo[k][l];
                        }
                        if(t == target){
                            count++;
                        }
                    }
                }
            }
        }
        
        return count;
    }
};