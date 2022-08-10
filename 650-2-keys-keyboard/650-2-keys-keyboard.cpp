class Solution {
    vector<bool> isprime;
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        cribe();
        
        if(isprime[n]) return n;
        
        vector<int> DP(n + 1, 0);
        DP[0] = 0;
        DP[1] = 0;
        
        for(int i = 2; i <= n; ++i) {
            DP[i] = i;
            if(!isprime[i]) {
                for(int j = 2; j < i; ++j) {
                    if(i%j == 0) {
                        DP[i] = min(DP[i], (i - j)/j + DP[j] + 1);
                    }
                }
            }
        }
        
        return DP[n];
    }
    
    void cribe() {
        isprime = vector<bool>(1001, true);
        
        for(int i = 2; i <= 1000; ++i) {
            if(!isprime[i]) continue;
            for(int j = 2*i; j <= 1000; j+=i) {
                isprime[j] = false;
            } 
        }
    }
};