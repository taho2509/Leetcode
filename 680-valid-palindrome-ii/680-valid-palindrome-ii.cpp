class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        
        int i = 0, j = n - 1;
        int deleted = 0;
        while(i < j) {
            if(s[i] != s[j]) {
                deleted++;
                if(deleted > 1) break;
                
                ++i;
                continue;
            }
            ++i;
            --j;
        }
        
        if(deleted <= 1) return true;
        
        i = 0, j = n - 1;
        deleted = 0;
        while(i < j) {
            if(s[i] != s[j]) {
                deleted++;
                if(deleted > 1) break;
                
                --j;
                continue;
            }
            ++i;
            --j;
        }
        
        return deleted <= 1;
    }
};