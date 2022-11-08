class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        
        for(int i = 0; i < n - 1; ++i) {
            if(s[i] >= 97) {
                if(s[i + 1] - 'A' == s[i] - 'a') {
                    return makeGood(s.substr(0,i) + s.substr(i + 2));
                }
            } else {
                if(s[i + 1] - 'a' == s[i] - 'A') {
                    return makeGood(s.substr(0,i) + s.substr(i + 2));
                }
            }
        }
        
        return s;
    }
};