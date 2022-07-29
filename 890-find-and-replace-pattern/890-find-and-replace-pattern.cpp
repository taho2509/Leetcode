class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(string w: words) {
            if(match(w, pattern)) ans.push_back(w);
        }
        
        return ans;
    }
    
    bool match(string &word, string &pattern) {
        int n = word.size();
        
        vector<int> permutation(26, -1);
        
        for(int i = 0; i < n; ++i) {
            if(permutation[word[i] - 'a'] == -1) {
                permutation[word[i] - 'a'] = pattern[i] - 'a';
            } else {
                if(permutation[word[i] - 'a'] != pattern[i] - 'a') return false;
            }
        }
        
        vector<int> inverse(26, -1);
        
        for(int i = 0; i < n; ++i) {
            if(inverse[pattern[i] - 'a'] == -1) {
                inverse[pattern[i] - 'a'] = word[i] - 'a';
            } else {
                if(inverse[pattern[i] - 'a'] != word[i] - 'a') return false;
            }
        }
        
        return true;
    }
};