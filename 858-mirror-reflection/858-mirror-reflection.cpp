class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(q == 0) return 0;
        if(p == q) return 1;
        
        bool left = true;
        int height = 0;
        
        while(true) {
            height += q;
            left = !left;
            if(height % p == 0) break;
        }
        
        if(left) return 2;
        
        return height % (2*p) == 0 ? 0 : 1;
    }
};