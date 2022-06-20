bool compare(string &a, string &b) {
    int n = a.size() - 1;
    int m = b.size() - 1;
    
    while(n >= 0 && m >= 0 && a[n] == b[m]) {
        n--;
        m--;
    }
    
    if(n < 0) return false;
    if(m < 0) return true;
    return a[n] < b[m];
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        string word = words[0];
        word += '#';
        
        for(int i = 1; i < words.size(); ++i) {
            if(!fits(word, words[i])) {
                word += words[i];
                word += '#';
            }
        }
        
        return word.size();
    }

    bool fits(string &word, string current) {
        int n = word.size() - 2;
        int m = current.size() - 1;
        
        while(n >= 0 && m >= 0 && word[n] == current[m]) {
            n--;
            m--;
        }
        
        if(m < 0) return true;
        return false;
    }
};