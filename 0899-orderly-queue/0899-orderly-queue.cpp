class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1) {
            sort(s.begin(), s.end());
            return s;
        } else {
            set<string> ord;
            int n = s.size();
            for(int i = 0; i < n; ++i) {
                ord.insert(s.substr(i) + s.substr(0, i));
            }
            return *ord.begin();
        }
    }
};