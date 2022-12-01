class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int count = 0;
        
        for(int i = 0; i < n; ++i) {
            if(i < n/2) {
                if(isVowel(s[i])) ++count;
            } else {
                if(isVowel(s[i])) --count;
                if(count < 0) return false;
            }
        }
        
        return count == 0;
    }
    
    bool isVowel(char &c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        
        return false;
    }
};