/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        
        queue<Node*> q;
        
        if(root != nullptr) q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            vector<int> v(n);
            
            for(int i = 0; i < n; ++i) {
                auto t = q.front();
                q.pop();
                v[i] = t->val;
                for(auto c: t->children) q.push(c);
            }
            
            ans.push_back(v);
        }
        
        return ans;
    }
};