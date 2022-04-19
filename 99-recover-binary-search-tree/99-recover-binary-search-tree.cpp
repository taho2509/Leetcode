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
    TreeNode* first = nullptr, *second = nullptr, *previous;
public:
    void recoverTree(TreeNode* root) {
        previous = new TreeNode(INT_MIN);
        inorder(root);
        swap(first->val, second->val);
    }
    
    void inorder(TreeNode* root) {
        if(root == nullptr) return;
        
        inorder(root->left);
        
        if(root->val < previous->val) {
            if(first == nullptr) {
                first = previous;
                second = root;
            } else {
                second = root;
            }
        }
        
        previous = root;

        inorder(root->right);
    }
};