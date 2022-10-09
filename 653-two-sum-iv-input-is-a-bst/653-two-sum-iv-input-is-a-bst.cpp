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
class Solution {
    bool ans;
    unordered_set<int> found;
public:
    bool findTarget(TreeNode* root, int k) {
        ans = false;
        
        inorder(root, k);
        
        return ans;
    }
    
    void inorder(TreeNode* root, int k) {
        if(root == nullptr) return;
        if(ans) return;
        
        inorder(root->left, k);
        if(found.count(k - root->val) != 0) {
            ans = true;
            return;
        }
        found.insert(root->val);
        inorder(root->right, k);
    }
};