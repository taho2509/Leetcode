class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // first st: for each from 1 to n find if it appears 2 or 0 times O(n2) O(1) 
        //second st: sort nums, for each compare to previous, repeated consecutive, missing leap O(nlogn[sorting]) O(1)
        //third st: bitset, when marking if already true, repeated, if remain false, missing O(n) O(n)
        //fourth st: combination of xor and gauss
        bitset<10001> found;
        int duplicated = -1;
        int missing = -1;
        int r = 0;
        for(auto n: nums) {
            r += n;
            if(found[n]) {
                duplicated = n;
            } else {
                found[n] = 1;
            }
        }
        
        int s = (nums.size() * (nums.size() + 1))/2;
        
        return {duplicated, duplicated - r + s};
    }
};