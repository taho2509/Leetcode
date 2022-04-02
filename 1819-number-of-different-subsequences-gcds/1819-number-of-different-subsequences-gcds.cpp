class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int ans = 0;
        vector<bool> counts(200001, false);
        int maxi = 0;
        for(auto i: nums){
            maxi = max(maxi, i);
            counts[i] = true;
        }
        
        for(int i = 1; i <= maxi; ++i) {
            int gc = 0;
            for(int j = i; j <= maxi; j += i) {
                if(counts[j]) {
                    gc = __gcd(gc, j);
                    if(gc == i) {
                        ++ans;
                        break;
                    }
                }
            }
        }
        
        
        return ans;
    }
};