class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "";
        
        for(auto c: s) {
            if(isVowel(c)) vowels += c;
        }
        
        int n = vowels.size() - 1;
        
        for(char &c: s) {
            if(isVowel(c)) {
                c = vowels[n--];
            }
        }
        
        return s;
    }
    
    bool isVowel(char &c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }
};