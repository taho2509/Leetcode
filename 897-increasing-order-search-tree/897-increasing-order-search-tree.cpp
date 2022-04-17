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
public:
    TreeNode* increasingBST(TreeNode* root) {
        return help(root, nullptr);
    }
    
    TreeNode* help(TreeNode* root, TreeNode* parent) {
        if(root == nullptr) return parent;
        
        TreeNode* left = root->left;
        root->right = help(root->right, parent);
        root->left = nullptr;
        return help(left, root);
    }
};