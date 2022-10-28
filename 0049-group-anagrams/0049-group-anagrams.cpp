class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> groups;
        for(string s: strs) {
            string ss = s;
            sort(ss.begin(), ss.end());
            groups[ss].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto it: groups) ans.push_back(it.second);
        return ans;
    }
};