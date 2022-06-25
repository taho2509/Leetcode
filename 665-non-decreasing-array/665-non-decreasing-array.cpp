class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MAX);
        
        int n = nums.size();
        int changes = 0;
        for(int i = 1; i < n - 1; ++i) {
            if(nums[i] > nums[i + 1]) {
                if(nums[i - 1] > nums[i + 1]) {
                    nums[i + 1] = nums[i];
                } else {
                    nums[i] = nums[i + 1];
                }
                changes++;
            }
            if(changes > 1) return false;
        }
        
        return true;
    }
};