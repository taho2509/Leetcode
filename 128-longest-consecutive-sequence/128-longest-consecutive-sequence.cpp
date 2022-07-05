class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> check;
        
        for(auto n: nums) {
            check[n] = -1;
        }
        
        int ans = 0;
        
        for(auto [k, v]: check) {
            if(v != -1) continue;
            int current = k;
            int count = 1;
            while(check.find(current + 1) != check.end()) {
                if(check[current + 1] != -1) {
                    count += check[current + 1];
                    break;
                }
                ++count;
                current = current + 1;
                check[current] = 0;
            }
            check[k] = count;
            ans = max(ans, count);
        }
        
        return ans;
    }
};