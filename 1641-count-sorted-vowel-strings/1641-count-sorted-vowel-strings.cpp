class Solution {
public:
    int c;
    void count(int last, int n) {
        if(n == 0) return;
        
        if(n == 1) c++;
        
        for(int i = last; i < 5; i++) {
            count(i, n - 1);
        }
    }
    
    int countVowelStrings(int n) {
        for(int i = 0; i < 5; ++i) count(i, n);
        return c;
    }
};