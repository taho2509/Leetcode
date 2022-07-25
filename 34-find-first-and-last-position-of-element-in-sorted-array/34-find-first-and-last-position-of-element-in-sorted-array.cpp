class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};

        vector<int>::iterator start = lower_bound(nums.begin(), nums.end(), target);
        
        if(start == nums.end()) return {-1,-1};
        
        if(*start != target) return {-1,-1};
        
        vector<int>::iterator end = upper_bound(nums.begin(), nums.end(), target);
        end--;
        
        return {(int)(start - nums.begin()), (int)(end - nums.begin())};
    }
};