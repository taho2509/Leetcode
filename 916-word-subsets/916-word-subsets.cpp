class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> hash(26, 0);
        
        for(string s: B) {
            vector<int> t(26, 0);
            for(char c: s) {
                t[c - 'a']++;
                hash[c - 'a'] = max(hash[c - 'a'], t[c - 'a']);
            }
        }
        
        int total = 0;
        for(int h: hash) {
            total += h;
        }
        
        if(total > 10) return {};
        
        vector<string> ans;
        for(int i = 0; i < A.size(); ++i) {
            if(contains(A[i], hash)) {
                ans.push_back(A[i]);
            }
        }
        
        return ans;
    }
    
    bool contains(string &s, vector<int> &hash) {
        vector<int> t(26, 0);
        for(char c: s) {
            t[c - 'a']++;
        }
        
        for(int i = 0; i < 26; ++i) {
            if(hash[i] != 0 && t[i] < hash[i]) return false;
        }
        
        return true;
    }
};