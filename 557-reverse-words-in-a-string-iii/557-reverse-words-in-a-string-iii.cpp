class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int last = 0;
        for(int k = 0; k < n; ++k) {
            if(s[k] == ' ') {
                int i = last, j = k - 1;
                while(i < j) {
                    swap(s[i++], s[j--]);
                }
                last = k + 1;
            }
        }
        
        int i = last, j = n - 1;
        while(i < j) {
            swap(s[i++], s[j--]);
        }
        
        return s;
    }
};