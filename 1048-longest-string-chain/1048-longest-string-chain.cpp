class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string a, string b) -> bool {
            return a.size() < b.size();
        });
        
        unordered_map<string,int> large;
        int m = 0;
        for(string s: words){
            large[s] = 1;
            
            for(int i = 0; i < s.size(); ++i) {
                string ss = s.substr(0,i) + s.substr(i + 1);
                if(large.count(ss) != 0) {
                    large[s] = max(large[s], 1 + large[ss]);
                }
            }
            m = max(m, large[s]);
        }
        
        return m;
    }
};