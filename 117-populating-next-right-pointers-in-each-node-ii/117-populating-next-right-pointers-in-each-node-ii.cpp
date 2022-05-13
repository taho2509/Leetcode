/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*> q;
        vector<Node*> v;
        q.push(root);
        
        while(!q.empty()) {
            while(!q.empty()) {
                v.push_back(q.front());
                q.pop();
            }
            
            for(int i = 0; i < v.size() - 1; i++) {
                v[i]->next = v[i + 1];
                if(v[i]->left != NULL)
                    q.push(v[i]->left);
                if(v[i]->right != NULL)
                    q.push(v[i]->right);
            }
            if(v[v.size() - 1]->left != NULL)
                q.push(v[v.size() - 1]->left);
            if(v[v.size() - 1]->right != NULL)
                q.push(v[v.size() - 1]->right);
            v.clear();
        }
        
        return root;
    }
};