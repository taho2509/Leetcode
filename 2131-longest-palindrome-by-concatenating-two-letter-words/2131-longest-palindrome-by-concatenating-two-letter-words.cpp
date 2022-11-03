class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> counts;
        for(auto s: words) counts[s]++;
        
        int length = 0;
        bool imp = false;
        
        for(auto [k, v]: counts) {
            if(k[0] == k[1]) {
                if(v % 2 == 0) {
                    length += v*2;
                    counts[k] -= v;
                } else {
                    length += (v - 1)*2;
                    counts[k] -= (v - 1);
                    imp = true;
                }
            } else {
                string revK = {k[1],k[0]};
                if(counts.count(revK) != 0) {
                    int sub = min(v,counts[revK]);
                    length += sub*4;
                    counts[k] -= sub;
                    counts[revK] -= sub;
                }
            }
        }
        
        return imp ? length + 2 : length;
    }
};