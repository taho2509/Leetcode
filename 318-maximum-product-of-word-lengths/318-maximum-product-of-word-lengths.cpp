class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> processed(n);
        
        for(int i = 0; i < n; ++i) {
            int letters = 0;
            for(char c: words[i]) {
                letters = letters | (1 << (c - 'a'));
            }
            processed[i] = letters;
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if((processed[i] & processed[j]) == 0) {
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        
        return ans;
    }
};