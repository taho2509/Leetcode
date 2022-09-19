class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        // key: content(or hash) value: filepath
        unordered_map<string, vector<string>> duplicates;
        
        for(string s: paths) {
            vector<string> splitted = split(s, ' ');
            
            for(int i = 1; i < splitted.size(); ++i) {
                auto [name, content] = getNameAndContent(splitted[i]);
                duplicates[content].push_back(splitted[0] + '/' + name);
            }
        }
        
        vector<vector<string>> ans;
        for(auto [k, v]: duplicates) {
            if(v.size() > 1) {
                ans.push_back(v);
            }
        }
        return ans;
    }
    
    pair<string, string> getNameAndContent(string &s) {
        vector<string> splitted = split(s, '(');
        splitted[1] = splitted[1].substr(0, splitted[1].size() - 1);
        return {splitted[0],splitted[1]};
    }
    
    vector<string> split(string s, char divisor) {
        stringstream test(s);
        string segment;
        vector<string> seglist;

        while(getline(test, segment, divisor))
        {
           seglist.push_back(segment);
        }
        
        return seglist;
    }
    
};