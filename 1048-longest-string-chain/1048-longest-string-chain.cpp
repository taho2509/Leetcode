class Solution {
vector<int> visited;
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string a, string b) -> bool {return a.size() < b.size();});
        visited = vector<int>(words.size(), -1);

        int m = 0;
        for(int i = 0; i < words.size(); ++i) {
            m = max(m, 1 + check(words, i));
        }
        
        return m;
    }
    
    int check(vector<string>& words, int i) {
        if(i == words.size()) return 0;
        if(visited[i] != -1) return visited[i];
        int m = 0;
        for(int j = i + 1; j < words.size(); ++j) {
            if(words[i].size() + 1 < words[j].size()) break;
            if(words[i].size() + 1 == words[j].size()) {
                if(predecessor(words[i], words[j])) {
                    m = max(m, 1 + check(words, j));
                }
            }
        }
        
        visited[i] = m;

        return m;
    }
    
    bool predecessor(string &s1, string &s2) {
        bool one = false;
        for(int i = 0; i < s1.size(); ++i) {
            if(one) {
                if(s1[i] != s2[i + 1]) {
                    return false;
                }
            } else {
                if(s1[i] != s2[i]) {
                    one = true;
                    --i;
                }
            }
        }
        return true;
    }
};