struct Node {
    int key;
    int val;
    Node* left;
    Node* right;
};

class LRUCache {
    unordered_map<int, Node*> q;
    int add;
    int capacity;
    Node* back;
    Node* front;
    
    int remove(int key) {
        if(q.find(key) == q.end()) return -1;
        
        if(back == front) {
            int val = back->val;
            delete back;
            back = front = nullptr;
            return val;
        }
        
        Node* current = q[key];
        int val = current->val;
        
        if(current->key == back->key) {
            back = back->left;
            back->right = nullptr;
            q.erase(key);
            return val;
        }
        
        if(current->key == front->key) {
            front = front->right;
            front->left = nullptr;
            q.erase(key);
            return val;
        }
        
        Node* t = current->left;
        t->right = current->right;
        current->right->left = current->left;
        q.erase(key);
        
        return val;
    }
    
    void push(int key, int val) {
        Node* node = new Node{key, val, nullptr, nullptr};
        if(front == nullptr) {
            front = back = node;
            q[key] = node;
            return;
        }
        
        node->left = back;
        back->right = node;
        back = node;
        q[key] = node;
    }
    
    void pop() {
        if(add > capacity) {
            if(front->right == nullptr) {
                q.erase(front->key);
                front = back = nullptr;
                return;
            }
            front = front->right;
            q.erase(front->left->key);
            front->left = nullptr;
        }
    }
public:
    LRUCache(int capacity):capacity(capacity), add(0) {
        back = front = nullptr;
    }
    
    int get(int key) {
        if(q.find(key) == q.end()) return -1;
        int val = remove(key);
        push(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if(q.find(key) == q.end()) {
            ++add;
            pop();
        }
        remove(key);
        push(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */