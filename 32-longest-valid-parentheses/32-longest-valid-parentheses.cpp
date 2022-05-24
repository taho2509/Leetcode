class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> pos;
        
        pos.push(-1);
        int m = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                pos.push(i);
            } else {
                pos.pop();
                if(pos.empty()) {
                    pos.push(i);
                } else {
                    m = max(m, i - pos.top());
                }
            }
        }
        return m;
    }
};