class Solution {
public:
    int maxScore(vector<int>& P, int k) {
        int n = P.size();
        int ans = 0;
        
        for(int i = n - 1; i >= n - k; --i) {
            ans += P[i];
        }
        
        int s = ans;
        for(int i = 0; i < k; ++i) {
            s += P[i];
            s -= P[i + n - k];
            ans = max(ans, s);
        }
        
        return ans;
    }
};