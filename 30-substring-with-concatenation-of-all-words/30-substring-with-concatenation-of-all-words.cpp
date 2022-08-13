class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int ind = words[0].size();
        int m = words.size();
        int n = s.size();
        
        unordered_map<string, int> counts;
        
        for(auto w: words) {
            counts[w]++;
        }
        
        
        vector<int> ans;
        for(int i = 0; i + ind*m <= n; ++i) {
            unordered_map<string, int> current;
            
            bool ok = true;
            for(int j = 0; j + ind <= ind*m; j += ind) {
                string t = s.substr(i + j, ind);
                if(counts.count(t) == 0) {
                    ok = false;
                    break;
                }
                current[t]++;
            }
            
            if(ok && current == counts) ans.push_back(i);
        }
        
        return ans;
    }
};