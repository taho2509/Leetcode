class Solution {
public:
    int romanToInt(string s) {
        int n = 0;
        int sz = s.size();
        
        for(int i = 0; i < sz; ++i) {
            int current = getValue(s[i]);
            if(i + 1 < sz) {
                if(current == 1) {
                    if(s[i + 1] == 'V') {
                        current = 4;
                        i++;
                    } else if(s[i + 1] == 'X') {
                        current = 9;
                        i++;
                    }
                } else if(current == 10) {
                    if(s[i + 1] == 'L') {
                        current = 40;
                        i++;
                    } else if(s[i + 1] == 'C') {
                        current = 90;
                        i++;
                    }
                } else if(current == 100) {
                    if(s[i + 1] == 'D') {
                        current = 400;
                        i++;
                    } else if(s[i + 1] == 'M') {
                        current = 900;
                        i++;
                    }
                }
            }
            n += current;
        }
        
        return n;
    }
    
    int getValue(char c) {
        switch (c){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
};