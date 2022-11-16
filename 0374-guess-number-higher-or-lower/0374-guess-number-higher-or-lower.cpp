/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start = 1, end = n;
        while(start < end) {
            int m = start + (end - start)/2;
            int g = guess(m);
            if(g == 0) return m;
            if(g > 0) {
                start = m + 1;
            } else {
                end = m - 1;
            }
        }
        
        return start;
    }
};