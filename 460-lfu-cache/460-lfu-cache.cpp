#define g0(x) std::get<0>(x)
#define g1(x) std::get<1>(x)
#define g2(x) std::get<2>(x)
struct Node {
    int key;
    int val;
    Node* left;
    Node* right;
};

class LFUCache {
    map<int, tuple<unordered_map<int,Node*>, Node*, Node*>> qs;
    unordered_map<int, Node*> q;
    vector<int> counter;

    int add;
    int capacity;
    Node* back;
    Node* front;
    
    int remove(int key) {
        if(counter[key] == 0) return -1;
        int freq = counter[key];

        if(g1(qs[freq]) == g2(qs[freq])) {
            int val = g2(qs[freq])->val;
            qs.erase(freq);
            return val;
        }
        
        Node* current = g0(qs[freq])[key];
        int val = current->val;
        
        if(current->key == g2(qs[freq])->key) {
            g2(qs[freq]) = g2(qs[freq])->left;
            g2(qs[freq])->right = nullptr;
            g0(qs[freq]).erase(key);
            return val;
        }
        
        if(current->key == g1(qs[freq])->key) {
            g1(qs[freq]) = g1(qs[freq])->right;
            g1(qs[freq])->left = nullptr;
            g0(qs[freq]).erase(key);
            return val;
        }
        
        g0(qs[freq])[key]->left->right = g0(qs[freq])[key]->right;
        g0(qs[freq])[key]->right->left = g0(qs[freq])[key]->left;
        g0(qs[freq]).erase(key);
        
        return val;
    }
    
    void push(int key, int val, int freq) {
        Node* node = new Node{key, val, nullptr, nullptr};
        
        if(g1(qs[freq]) == nullptr) {
            g1(qs[freq]) = node;
            g2(qs[freq]) = node;
            g0(qs[freq])[key] = node;
            return;
        }
        
        node->left = g2(qs[freq]);
        g2(qs[freq])->right = node;
        g2(qs[freq]) = node;
        g0(qs[freq])[key] = node;
    }
    
    void pop() {
        if(add > capacity) {
            auto it = qs.begin();
            int freq = it->first;
            
            counter[g1(it->second)->key] = 0;
            if(g1(it->second)->right == nullptr) {
                qs.erase(freq);
                return;
            }
            g1(it->second) = g1(it->second)->right;
            
            q.erase(g1(it->second)->left->key);
            g1(it->second)->left = nullptr;
        }
    }
    
public:
    LFUCache(int capacity):capacity(capacity), add(0) {
        back = front = nullptr;
        counter = vector<int>(100001, 0);
    }
    
    int get(int key) {
        if(counter[key] == 0) return -1;

        int val = remove(key);

        push(key, val, counter[key] + 1);
        counter[key]++;
        return val;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(counter[key] == 0) {
            ++add;
            pop();
        }
        remove(key);
        push(key, value, counter[key] + 1);
        counter[key]++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */