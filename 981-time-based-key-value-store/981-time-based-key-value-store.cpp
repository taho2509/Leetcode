class TimeMap {
    unordered_map<string,map<int,string>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(store.count(key) == 0) return "";
        
        auto it = store[key].lower_bound(timestamp);
        if(store[key].begin() == store[key].end()) return "";
        if(it == store[key].end()) {
            --it;
            return it->second;
        }
        if(it == store[key].begin()) {
            if(it->first > timestamp) return "";
            return it->second;
        }
        if(it->first == timestamp) return it->second;
        --it;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */