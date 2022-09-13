class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        
        int i = 0;
        while(i < n) {
            int type = getType(data[i]);
            if(type == 5) return false;
            if(i + type > n) return false;
            
            int j = i + 1;
            for(; j < i + type; ++j) {
                if(!(128 & data[j])) return false;
                if(!(64 ^ (data[j] & 64))) return false;
            }
            
            i = j;
        }
        
        return true;
    }
    
    int getType(int byte) {
        int onemask = 128;
        if(onemask ^ (byte & onemask)) return 1;
        
        int twomask = 192;
        if(twomask & byte) {
            if((byte & 32) ^ (32)) return 2;
        }
        
        int threemask = 224;
        if(threemask & byte) {
            if((byte & 16) ^ (16)) return 3;
        }
        
        int fourmask = 240;
        if(fourmask & byte) {
            if((byte & 8) ^ (8)) return 4;
        }
        
        return 5;
    }
};