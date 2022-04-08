class KthLargest {
    priority_queue<int> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums): k(k) {
        for(auto n: nums) pq.push(-n);
        
        while(pq.size() > k) {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(-val);
        while(pq.size() > k) {
            pq.pop();
        }
        return -pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */