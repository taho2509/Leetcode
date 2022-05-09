#define mod 1000000007
class Solution {
public:
    int countTexts(string keys) {
        int ans = 0;
        int n = keys.size();
        vector<int> mm{0,0,3,3,3,3,3,4,3,4};
        vector<int> DP(n + 1, 0);
        DP[0] = 1; 
        
        for(int i = 0; i < n; ++i) {
            int l = mm[keys[i] - '0'];
            int t = 0;
            while(t < l && i - t >= 0 && keys[i - t] == keys[i] ) {
                DP[i + 1] += DP[i - t];
                DP[i + 1] = DP[i + 1] % mod;
                ++t;
            }
        }
        
        return DP[n];
    }
};