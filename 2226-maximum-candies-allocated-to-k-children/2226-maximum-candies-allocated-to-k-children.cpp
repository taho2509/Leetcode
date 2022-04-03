class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int end = *max_element(candies.begin(), candies.end());
        int start = 1;
        
        while(start < end) {
            int m = (start + end)/2;
            
            if(can(candies, k, m)) {
                start = m + 1;
            } else {
                end = m - 1;
            }
        }
        
        if(!can(candies, k, start)) return start - 1;
        return start;
    }
    
    bool can(vector<int>& candies, long long k, int a) {
        int n = candies.size();
        for(int i = 0; i < n; ++i) {
            k -= candies[i]/a;
            if(k <= 0) return true;
        }
        
        return false;
    }
};