class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> groups;
        for(string s: strs) {
            groups[hash(s)].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto it: groups) ans.push_back(it.second);
        return ans;
    }
    
    vector<int> hash(string &s) {
        vector<int> h(26, 0);
        
        for(char &a: s) h[a - 'a']++;
        return h;
    }
};