class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        
        string say = countAndSay(n - 1);
        
        string result = "";
        
        char current = say[0];
        int count = 1;
        for(int i = 1; i < say.size(); i++) {
            if(current != say[i]) {
                result += to_string(count);
                result += current;
                current = say[i];
                count = 1;
            } else {
                count++;
            }
        }
        result += to_string(count);
        result += current;
        
        return result;
    }
};