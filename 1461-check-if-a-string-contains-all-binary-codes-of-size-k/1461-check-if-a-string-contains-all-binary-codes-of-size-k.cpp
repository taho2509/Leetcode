class Solution {
int count;
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int target = pow(2,k);
        count = 0;
        TreeNode* root = new TreeNode('*');
        for(int i = 0; i < n - k + 1 && count != target; ++i) {
            insert(root, s, i, k);
        }
        
        return count == target;
    }
    
    TreeNode* insert(TreeNode *root, string &s, int start, int k) {
        if(k == 0) {
            if(root != nullptr) return root;
            count++;
            return new TreeNode(s[start]);
        }
        
        if(root == nullptr) {
            root = new TreeNode(s[start]);
        }
        
        if(s[start] == '0') {
            root->left = insert(root->left, s, start + 1, k - 1);
        } else {
            root->right = insert(root->right, s, start + 1, k - 1);
        }
        
        return root;
    }
};