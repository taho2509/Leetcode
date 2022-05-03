class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy(nums.begin(), nums.end());
        
        sort(copy.begin(), copy.end());
        
        int start = nums.size();
        int end = -1;
        bool sorted = true;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != copy[i]) {
                sorted = false;
                start = min(start, i);
                end = max(end, i);
            }
        }
        
        return sorted ? 0 : end - start + 1;
    }
};