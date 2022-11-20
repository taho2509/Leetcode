struct element {
    bool op;
    int value;
    char type;
};

class Solution {
    unordered_map<char, function<int(int,int)>> operations;
public:
    int calculate(string s) {
        stack<element> st;
        operations['+'] = [](int a, int b) -> int {return a + b;};
        operations['-'] = [](int a, int b) -> int {return a - b;};
        
        int n = s.size();
        
        for(int i = 0; i < n; ++i) {
            int a, b;
            switch(s[i]) {
                case '(':
                case '+':
                    st.push({true, 0, s[i]});
                    break;
                case '-':
                    if(st.empty() || st.top().type == '(') st.push({false, 0, '*'});
                    st.push({true, 0, s[i]});
                    break;
                case ')':
                    b = st.top().value;
                    st.pop();// number
                    st.pop();// (
                    if(!st.empty() && (st.top().type == '+' || st.top().type == '-')) {
                        char op = st.top().type;
                        st.pop(); // +-
                        int a = st.top().value;
                        st.pop();// number
                        st.push({false, operations[op](a, b), '*'});
                    } else {
                        st.push({false, b, '*'});
                    }
                    break;
                case ' ':
                    break;
                default:
                    b = getNumber(s, i);
                    if(!st.empty() && (st.top().type == '+' || st.top().type == '-')) {
                        char op = st.top().type;
                        st.pop(); // +-
                        int a = st.top().value;
                        st.pop();// number
                        st.push({false, operations[op](a, b), '*'});
                    } else {
                        st.push({false, b, '*'});
                    }
            }
        }

        
        return st.top().value;
    }
    
    int getNumber(string &s, int &i) {
        int n = s.size();
        string num = "";
        while(i < n && s[i] >= '0' && s[i] <= '9') {
            num += s[i];
            i++;
        }
        --i;
        return stoi(num);
    }
};