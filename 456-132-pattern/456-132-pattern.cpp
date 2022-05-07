class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3) return false;
        
        stack<int> st;
        int thirdElement = INT_MIN;
        
        for(int i = n - 1; i >= 0; --i) {
            if(nums[i] < thirdElement) return true;
            while(!st.empty() && st.top() < nums[i]) {
                thirdElement = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};