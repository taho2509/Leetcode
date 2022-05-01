class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return enter(s) == enter(t);
    }
    
    string enter(string s) {
        stack<char> st;
        int n = s.size();
        
        for(int i = 0; i < n; ++i) {
            if(s[i] == '#') {
                if(!st.empty()) st.pop();
            } else {
                st.push(s[i]);
            }
        }
        
        string r;
        while(!st.empty()) {
            r += st.top();
            st.pop();
        }
        
        return r;
    }
};