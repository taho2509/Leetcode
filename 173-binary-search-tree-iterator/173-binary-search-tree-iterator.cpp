/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> s;
    TreeNode* root;
    TreeNode* current;
public:
    BSTIterator(TreeNode* root):root(root) {
        current = root;
        go();
    }
    
    void go() {
        while(current->left != nullptr) {
            s.push(current);
            current = current->left;
        }
    }
    
    int next() {
        int v = current->val;
        if(current->right != nullptr) {
            current = current->right;
            go();
        } else {
            if(!s.empty()) {
                current = s.top();
                s.pop();
            } else {
                current = nullptr;
            }
        }
        return v;
    }
    
    bool hasNext() {
        return s.size() > 0 || current != nullptr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */