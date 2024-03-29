/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int c = root->val;
        int pv = p->val;
        int qv = q->val;
        
        if(pv < c && qv < c) return lowestCommonAncestor(root->left, p, q);
        if(pv > c && qv > c) return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
};