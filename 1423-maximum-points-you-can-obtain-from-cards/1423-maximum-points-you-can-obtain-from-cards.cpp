class Solution {
public:
    int maxScore(vector<int>& P, int k) {
        int n = P.size();
        vector<int> accum(n + 1, 0);

        for(int i = 0; i < n; ++i) {
            accum[i + 1] = P[i];
            accum[i + 1] += accum[i];
        }
        
        int total = accum[n];
        
        if(k == n) return total;
        
        int ans = 0;
        
        for(int i = 0; i < k + 1; ++i) {
            ans = max(ans, accum[i] + accum[n] - accum[i + n - k]);
        }
        
        return ans;
    }
};