class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int start = 0, end = 0;
        int ans = INT_MAX;
        
        start = *max_element(nums.begin(), nums.end());
        end = accumulate(nums.begin(), nums.end(), 0);
        
        while(start <= end) {
            int medio = (start + end)/2;
            
            if(can_fit_in(nums, medio, m)) {
                ans = min(ans, medio);
                end = medio - 1;
            } else {
                start = medio + 1;
            }
        }
        
        return ans;
    }
    
    bool can_fit_in(vector<int>& nums, int medio, int m) {
        int n = nums.size();
        int total = 0;
        int current = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] + current <= medio) {
                current += nums[i];
            } else {
                ++total;
                current = nums[i];
            }
        }
        ++total;
        
        return total <= m;
    }
};