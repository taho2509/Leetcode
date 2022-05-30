class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        long count = 0;
        long a = abs(dividend);
        long b = abs(divisor);
        long incr = 0;
        int factor = 1;
        
        while(incr + b <= a) {
            count += factor;
            incr += b;
            if(incr + b + b <= a) {
                b = b + b;
                factor = factor + factor;
            } else {
                factor = 1;
                b = abs(divisor);
            }
        }
        
        if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) return min((long)INT_MAX, count);
        else return -count;
    }
};