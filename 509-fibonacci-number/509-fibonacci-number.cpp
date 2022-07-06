class Solution {
public:
    int fib(int n) {
        vector<int> Fib(31, 0);
        
        Fib[0] = 0;
        Fib[1] = 1;
        for(int i = 2; i <= n; ++i) {
            Fib[i] = Fib[i - 1] + Fib[i - 2];
        }
        
        return Fib[n];
    }
};