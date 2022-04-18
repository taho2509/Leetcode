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
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
    
    int inorder(TreeNode* root, int &k) {
        if(root == nullptr) return -1;
        
        int t1 = inorder(root->left, k);
        if(t1 != -1) return t1;
        k--;
        
        if(k == 0) return root->val;
        
        t1 = inorder(root->right, k);
        return t1;
    }
};