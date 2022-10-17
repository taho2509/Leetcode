class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> exist;
        int count = 0;
        for(char c: sentence) {
            if(exist.find(c) == exist.end()) {
                ++count;
                exist.insert(c);
            }
        }
        
        return count == 26;
    }
};