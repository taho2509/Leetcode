class Solution {
int filled;
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        vector<int> rev;
        filled = 0;
        while(filled < n) {
            int next = getNext(stamp, target);
            if(next == -1) return {};
            rev.push_back(next);
        }
        
        return vector<int>(rev.rbegin(), rev.rend());
    }
    
    int getNext(string &stamp, string &target) {
        int n = target.size();
        int m = stamp.size();
        for(int i = 0; i < n - m + 1; ++i) {
            bool match = false;
            bool exit = false;
            int real = 0;
            for(int j = 0; j < m; ++j) {
                if(target[i + j] != '?' && stamp[j] != target[i + j]) {
                    exit = true;
                    break;
                }
                if(target[i + j] != '?') {
                    real++;
                    match = true;
                }
            }
            if(exit) continue;
            if(match) {
                for(int j = i; j < i + m; ++j) target[j] = '?';
                filled += real;
                return i;
            }
        }
        return -1;
    }
};