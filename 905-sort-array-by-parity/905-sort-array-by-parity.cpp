class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) -> bool {
           if(a%2 == b%2) {
               return a < b;
           } else {
               return a % 2 == 0;
           }
        });
        
        return nums;
    }
};