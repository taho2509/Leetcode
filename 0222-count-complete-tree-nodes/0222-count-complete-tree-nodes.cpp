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
     int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int lh = LH(root);
        int rh = RH(root);
        
        if(lh == rh) return (1 << lh) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int LH(TreeNode* root) {
        if(root == nullptr) return 0;
        
        return 1 + LH(root->left);
    }
    
    int RH(TreeNode* root) {
        if(root == nullptr) return 0;
        
        return 1 + RH(root->right);
    }
};