class Solution {
public:
    bool isPossible(vector<int>& nums) {  
        unordered_map<int,int> counter;
        unordered_map<int,int> ends;
        
        for(int n: nums) counter[n]++;
        
        
        for(int n: nums) {
            if(counter[n] != 0) {
                counter[n]--;                
                
                if(ends[n - 1] != 0) {
                    ends[n - 1]--;
                    ends[n]++;
                } else if(counter[n + 1] != 0 && counter[n + 2] != 0) {
                    counter[n + 1]--;
                    counter[n + 2]--;
                    ends[n + 2]++;
                } else return false;
            }
        }
        
        return true;
    }
};