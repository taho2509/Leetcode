class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.size();
        int prevprev = 0;
        int prev = 1;
        int current = 0;
        
        for(int i = 0; i < n; ++i) {
            current = 0;
            int t = stoi(s.substr(i, 1));
            if(t > 0) {
                current += prev;
            }

            if(i == 0){
                prevprev = prev;
                prev = current;
                continue;
            }
            t = stoi(s.substr(i - 1, 2));
            if(t == 0 || t < 10 || t > 26){
                prevprev = prev;
                prev = current;
                continue;
            }
            
            current += prevprev;
            prevprev = prev;
            prev = current;
        }
        
        return current;
    }
};