class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> found;
        int n = nums.size();
        ++k;
        
        if(k > n) k = n;
        
        for(int i = 0; i < k; ++i) {
            if(found.find(nums[i]) != found.end()) return true;
            found.insert(nums[i]);
        }
        
        for(int i = k; i < n; ++i) {
            found.erase(nums[i - k]);
            
            if(found.find(nums[i]) != found.end()) return true;
            found.insert(nums[i]);
        }
        
        return false;
    }
};