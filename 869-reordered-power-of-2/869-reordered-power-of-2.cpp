class Solution {
public:
    bool reorderedPowerOf2(int number) {
        int start = 1;
        string num = to_string(number);
        vector<string> pows;
        while(start < 1000000000) {
            string t = to_string(start);
            if(num.size() == t.size()) {
                pows.push_back(t);
            }
            start*=2;
        }
        for(string s: pows) {
            if(isAnagram(num, s)) return true;
        }
        return false;
    }
    
    bool isAnagram(string &num, string &s) {
        vector<bool> used(s.size(), false);
        for(char c: num) {
            bool found = false;
            for(int i = 0; i < s.size(); ++i) {
                if(!used[i] && s[i] == c) {
                    found = true;
                    used[i] = true;
                    break;
                }
            }
            if(!found) return false;
        }
        return true;
    }
};