#define kv pair<int,int>
#define mod 1000
class MyHashMap {
    vector<vector<kv>> hashmap;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        hashmap = vector<vector<kv>>(1000, vector<kv>());
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash = key % mod;
        for(int i = 0; i < hashmap[hash].size(); ++i) {
            if(hashmap[hash][i].first == key) {
                hashmap[hash][i].second = value;
                return;
            }
        }
        hashmap[hash].push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hash = key % mod;
        for(int i = 0; i < hashmap[hash].size(); ++i) {
            if(hashmap[hash][i].first == key) {
                return hashmap[hash][i].second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hash = key % mod;
        for(int i = 0; i < hashmap[hash].size(); ++i) {
            if(hashmap[hash][i].first == key) {
                hashmap[hash].erase(hashmap[hash].begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */