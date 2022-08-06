class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int a = minutesToTest/minutesToDie;
        
        int s = 0, e = buckets, m;
        while(s<e) {
            m = (s + e)/2;
            if(pow(a+1,m) >= buckets) {
                e = m;
            } else {
                s = m + 1;
            }
        }
        return s;
    }
};