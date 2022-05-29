class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<bool>> processed(n);
        
        for(int i = 0; i < n; ++i) {
            vector<bool> letters(26, false);
            for(char c: words[i]) {
                letters[c - 'a'] = true;
            }
            processed[i] = letters;
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(!collision(processed[i], processed[j])) {
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        
        return ans;
    }
    
    bool collision(vector<bool> &a, vector<bool> &b) {
        for(int i = 0; i < 26; ++i) {
            if(a[i] && b[i]) return true;
        }
        
        return false;
    }
};