class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<pair<char, int>> r;
        int n = s.size();
        r.push_back({'*', 0});
        
        for(int i = 0; i < n; ++i) {
            if(r.back().first == s[i]) {
                r.back().second++;
                r.back().second %= k;
                if(r.back().second == 0 && r.back().first != '*') r.pop_back();
            } else {
                r.push_back({s[i], 1});
            }
        }
        
        string ans = "";
        r.pop_front();
        while(!r.empty()) {
            auto [a, c] = r.front();
            r.pop_front();
            
            ans.append(c, a);
        }
        
        return ans;
    }
};