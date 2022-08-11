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
long last;
public:
    bool isValidBST(TreeNode* root) {
        last = LONG_MIN;
        return dfs(root);
    }
    
    bool dfs(TreeNode* root) {
        if(root == nullptr) return true;
        
        bool valid = true;
        
        valid &= dfs(root->left);
        if(root->val <= last) return false;
        last = root->val;
        valid &= dfs(root->right);
        return valid;
    }
};