class MyStack {
    queue<int> one;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        one.push(x);
    }
    
    int pop() {
        queue<int> two;
        while(one.size() > 1) {
            two.push(one.front());
            one.pop();
        }
        int ans = one.front();
        one.pop();
        while(!two.empty()) {
            one.push(two.front());
            two.pop();
        }
        return ans;
    }
    
    int top() {
        queue<int> two;
        while(one.size() > 1) {
            two.push(one.front());
            one.pop();
        }
        int ans = one.front();
        one.pop();
        while(!two.empty()) {
            one.push(two.front());
            two.pop();
        }
        one.push(ans);
        return ans;
    }
    
    bool empty() {
        return one.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */