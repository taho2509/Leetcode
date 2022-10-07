class MyCalendarThree {
    map<int,pair<int,int>> events;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        if(events.find(start) != events.end()) {
            events[start].first++;
        } else {
            events[start] = {1,0};
        }
        
        if(events.find(end) != events.end()) {
            events[end].second++;
        } else {
            events[end] = {0,1};
        }
        
        //print();
        
        int ans = 0;
        int current = 0;
        for(auto [k, v]: events) {
            current = current - v.second + v.first;
            ans = max(ans, current);
        }
        
        return ans;
    }
    
    void print() {
        for(auto [k, v]: events) {
            cout << k << " ";
            for(int i = 0; i < v.second; ++i) cout << ")";
            for(int i = 0; i < v.first; ++i) cout << "[";
            cout << " ";
        }
        cout << endl;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */