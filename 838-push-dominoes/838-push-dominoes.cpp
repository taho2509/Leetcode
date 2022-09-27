class Solution {
public:
    string pushDominoes(string s) {
        string ans = "";
        int l = 0;
        int n = s.size();
        int count = 0;

        for(int i = 0; i < n; ++i) {
            if(s[i] == 'R') {
                if(l != 0 && ans[l - 1] == 'R') ans += string(count, 'R');
                else ans += string(count, '.');
                l += count;
                count = 0;
                ans += 'R';
                ++l;
            } else if(s[i] == 'L') {
                if(l == 0) ans += string(count,'L');
                else if(ans[l - 1] == 'R') {
                    ans += string(count/2,'R');
                    if(count % 2 == 1) ans += '.';
                    ans += string(count/2,'L');
                } else if(ans[l - 1] == 'L') ans += string(count,'L');
                l += count;
                count = 0;
                ans += 'L';
                ++l;
            } else {
                ++count;
            }
        }
        if(count > 0) {
            if(l != 0 && ans[l - 1] == 'R') {
                ans += string(count, 'R');
            } else {
                ans += string(count, '.');
            }
        }
        return ans;
    }
};