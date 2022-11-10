class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n = s.size();
        
        for(int i = 0; i < n; ++i) {
            if(st.empty()) {
                st.push(s[i]);
            } else {
                if(st.top() == s[i]) {
                    while(!st.empty() && (st.top() == s[i])) {
                        st.pop();
                    }
                } else {
                    st.push(s[i]);
                }
            }
        }
        
        int sz = st.size();
        string ans = "";
        
        for(int i = sz - 1; i >= 0; --i) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};