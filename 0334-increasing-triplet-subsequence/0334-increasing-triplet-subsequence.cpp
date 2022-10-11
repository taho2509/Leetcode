class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> DP;
        vector<int> lis; // lis[i] contains lis at position i
        int n = nums.size();

        for(int i = 0; i < n; ++i) {
            auto it = upper_bound(DP.begin(), DP.end(), nums[i] - 1);
            lis.push_back(it - DP.begin() + 1);
            if(it == DP.end()) DP.push_back(nums[i]);
            else *it = nums[i];
        }
        
        return *max_element(lis.begin(), lis.end()) >= 3;
    }
};