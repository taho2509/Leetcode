class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int current = 0, next = 1;
        for(int i = next; i < nums.size(); i++) {
            if(nums[i] == nums[current]) continue;
            nums[++current] = nums[i];
        }
        
        return current + 1;
    }
};