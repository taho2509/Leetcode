class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        
        for(string s: ops) {
            int n = scores.size();
            if(s == "+") {
                scores.push_back(scores[n - 1] + scores[n - 2]);
            } else if(s == "D") {
                scores.push_back(scores[n - 1]*2);
            } else if(s == "C") {
                scores.pop_back();
            } else {
                scores.push_back(stoi(s));
            }
        }
        
        int ans = 0;
        for(auto s: scores) ans += s;
        
        return ans;
    }
};