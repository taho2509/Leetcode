class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> positions(26);
        
        for(int i = 0; i < s.size(); ++i) {
            positions[s[i] - 'a'].push_back(i);
        }
        
        int ans = 0;
        
        for(string w: words) {
            bool found = true;
            int at = -1;
            for(char c: w) {
                auto it = upper_bound(positions[c - 'a'].begin(), positions[c - 'a'].end(), at);
                if(it == positions[c - 'a'].end()) {
                    found = false;
                    break;
                }
                at = *it;
            }
            if(found) ++ans;
        }
        
        return ans;
    }
};