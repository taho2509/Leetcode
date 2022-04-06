class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        vector<int> S(301, 0);
        vector<int> D(301, 0);
        vector<int> T(301, 0);
        int n = arr.size();
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= target; ++j) {
                if(i >= 2) {
                    if(j - arr[i] >= 0) {
                        T[j] += D[j - arr[i]];
                        T[j] %= 1000000007;
                    }
                }
            }
            for(int j = 0; j <= target; ++j) {
                if(i >= 1) {
                    if(j - arr[i] >= 0) {
                        D[j] += S[j - arr[i]];
                        D[j] %= 1000000007;
                    }
                }
            }
            S[arr[i]]++;
        }
        
        return T[target];
    }
};