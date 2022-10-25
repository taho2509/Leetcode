class Solution {
#define pi pair<int,int>
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        pi pw1 = {0,0}, pw2 = {0,0};
        while(pw1.first != -1 && pw2.first != -1) {
            if(word1[pw1.first][pw1.second] != word2[pw2.first][pw2.second]) return false;
            pw1 = getNext(pw1, word1);
            pw2 = getNext(pw2, word2);
        }
        
        if(pw1.first != -1 || pw2.first != -1) return false;
        
        return true;
    }
    
    
    pi getNext(pi &current, vector<string>& word) {
        if(current.second + 1 < word[current.first].size()) return {current.first, current.second + 1};
        if(current.first + 1 < word.size()) return {current.first + 1, 0};
        return {-1,-1};
    }
};