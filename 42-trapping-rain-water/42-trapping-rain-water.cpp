class Solution {
public:
    int trap(vector<int>& H) {
        int n = H.size();
        if(n == 0) return 0;
        vector<int> M(n, 0);
        
        M[0] = H[0];
        for(int i = 1; i < n; ++i) {
            M[i] = max(M[i - 1], H[i]);
        }
        
        int cm = 0;
        for(int i = n - 1; i >= 0; --i) {
            cm = max(cm, H[i]);
            
            M[i] = min(M[i], cm);
        }
        
        int accum = 0;
        for(int i = 0; i < n; ++i) {
            accum += M[i] - H[i];
        }
        
        return accum;
    }
};