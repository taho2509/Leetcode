class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        string original = palindrome;
        
        if(n == 1) return "";
        
        for(int i = 0; i < n/2; ++i) {
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a';
                break;
            }
        }
        
        if(palindrome == original) {
            palindrome[n - 1] = 'b';
        }
        
        return palindrome;
    }
};