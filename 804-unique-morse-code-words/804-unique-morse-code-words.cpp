class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> transformations;
        vector<string> alphabet{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(auto w: words) {
            string result = "";
            for(auto c: w) {
                result += alphabet[c - 'a'];
            }
            transformations.insert(result);
        }
        
        return transformations.size();
    }
};