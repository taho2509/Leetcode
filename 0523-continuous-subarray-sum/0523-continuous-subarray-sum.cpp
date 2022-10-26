class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, pre = 0;
        unordered_set<int> sums;
        
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sums.count(sum % k)) return true;
            sums.insert(pre);
            pre = sum % k;
        }
        return false;
    }
};