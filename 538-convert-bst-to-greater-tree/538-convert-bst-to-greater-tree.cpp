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
    TreeNode* convertBST(TreeNode* root) {
        
        help(root, 0);
        return root;
    }
    
    int help(TreeNode* root, int accum) {
        if(root == nullptr) return accum;
        
        int right = help(root->right, accum);
        root->val += right;
        return help(root->left, root->val);
    }
};