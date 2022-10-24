class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n < m) return "";

        vector<int> count(100, 0), current(100, 0);
        int len = 0;

        for (auto c : t) {
            count[c - 'A']++;
            ++len;
        }

        int j = 0, q = 0;
        int front, back;
        int mins = n + 1;
        for (int i = 0; i < n; ++i) {
            ++current[s[i] - 'A'];

            if ((count[s[i] - 'A'] > 0)) {
                if (current[s[i] - 'A'] <= count[s[i] - 'A'])
                    ++q;
            }
            
            if (q == len) {
                while (count[s[j] - 'A'] <= 0 || (current[s[j] - 'A'] > count[s[j] - 'A'])) {
                    if (current[s[j] - 'A'] > count[s[j] - 'A'])
                        --current[s[j] - 'A'];
                    ++j;
                }
                if(mins > i - j + 1) {
                    mins = i - j + 1;
                    front = i;
                    back = j;
                }
            }
        }
        
        if(mins > n) return "";
        return s.substr(back, front - back + 1);
    }
};