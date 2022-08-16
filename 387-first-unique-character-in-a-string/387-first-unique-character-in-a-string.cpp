class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> counts(26, 0);
        
        for(auto c: s) counts[c - 'a']++;
        
        int n = s.size();
        
        for(int i = 0; i < n; ++i) {
            if(counts[s[i] - 'a'] == 1) return i;
        }
        
        return -1;
    }
};