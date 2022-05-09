class Solution {
public:
    vector<string> letterCombinations(string d) {
        if(d == "") return {};
        
        return combi(d);
    }
    
    vector<string> combi(string d) {
        if(d.size() == 0) return {""};
        
        vector<string> l{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> f = combi(d.substr(1));
        
        vector<string> ans;
        for(char c: l[d[0] - '0']) {
            for(string s: f) {  
                string y = c + s;
                ans.push_back(y);
            }
        }
        
        return ans;
    }
};