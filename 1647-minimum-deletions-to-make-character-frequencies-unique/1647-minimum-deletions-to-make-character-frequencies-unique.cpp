class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(auto c: s) {
            freq[c - 'a']++;
        }
        
        sort(freq.begin(), freq.end());
        
        int acum = 0;
        int last = freq[25];
        
        for(int i = 24; i >= 0; i--) {
            if(freq[i] == 0) break;
            if(freq[i] >= last) {
                if(last == 0) {
                    acum+= freq[i];
                } else {
                    acum+= (freq[i] - (last - 1));
                    last--;
                }
            } else {
                last = freq[i];
            }
        }
        
        return acum;
    }
};