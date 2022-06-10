class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int n = s.size();
        int ans = 0;
        unordered_map<char, int> hash;
        
        while(i < n) {
            hash[s[i]]++;
            if(hash[s[i]] < 2) {
                ans = max(ans, i - j + 1);
            } else {
                while(hash[s[i]] >= 2 && j < i) {
                    hash[s[j]]--;
                    ++j;
                }
            }
            ++i;
        }
        
        return ans;
    }
};