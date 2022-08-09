#define mod 1000000007
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_set<int> nums(arr.begin(), arr.end());
        
        vector<long> DP(n, 1);
        int accum = DP[0];
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(arr[i]%arr[j] == 0 && nums.find(arr[i]/arr[j]) != nums.end()) {
                    int k = lower_bound(arr.begin(), arr.begin() + i + 1, arr[i]/arr[j]) - arr.begin();
                    DP[i] += DP[j]*DP[k];
                    DP[i] %= mod;
                }
            }
            accum += DP[i];
            accum %= mod;
        }
        
        return accum;
    }
};