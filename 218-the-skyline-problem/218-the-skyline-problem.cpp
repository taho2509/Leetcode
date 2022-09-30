struct B {
    int x;
    int y;
    bool start;
};

bool compare(B &a, B &b) {
    if(a.x < b.x) return true;
    if(a.x > b.x) return false;
    if(a.start != b.start) {
        return a.start;
    } else {
        if(a.start) {
            return a.y > b.y;
        } else {
            return a.y < b.y;
        }
    }
}

class Solution {
    priority_queue<int> removed;
    priority_queue<int> current;
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        removed = priority_queue<int>();
        current = priority_queue<int>();
        
        vector<B> builds;
        for(auto b: buildings) {
            builds.push_back({b[0], b[2], true});
            builds.push_back({b[1], b[2], false});
        }
        
        sort(builds.begin(), builds.end(), compare);
        
        
        vector<vector<int>> ans;
        
        
        current.push(0);
        int c;
        
        for(auto b: builds) {
            c = top();
            if(b.start) {
                current.push(b.y);
                if(c != top()) {
                    ans.push_back({b.x,b.y});
                }
            } else {
                remove(b.y);
                if(c != top()) {
                    ans.push_back({b.x, top()});
                }
            }
        }
        
        return ans;
    }
    
    void remove(int x) {
        removed.push(x);
    }
    
    int top() {
        while(!current.empty() && !removed.empty() && current.top() == removed.top()) {
            current.pop();
            removed.pop();
        }
        return current.top();
    }
};