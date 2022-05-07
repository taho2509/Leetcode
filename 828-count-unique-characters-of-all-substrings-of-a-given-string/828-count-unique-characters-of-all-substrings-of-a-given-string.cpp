class Solution {
public:
    int uniqueLetterString(string s) {
        vector<pair<int,int>> lastPosition(26, {0,0});
        
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            lastPosition[s[i] - 'A'].first = lastPosition[s[i] - 'A'].second;
            lastPosition[s[i] - 'A'].second = i + 1;
            for(int j = 0; j < 26; ++j) ans += lastPosition[j].second - lastPosition[j].first;
        }
        
        return ans;
    }
};