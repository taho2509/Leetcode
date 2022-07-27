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
    vector<int> elements;
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        
        preorder(root);
        
        TreeNode* start = new TreeNode(0);
        TreeNode* current = start;
        for(int e: elements) {
            current->right = new TreeNode(e);
            current = current->right;
        }
        
        start = start->right;
        
        root->left = nullptr;
        root->val = start->val;
        root->right = start->right;
    }
    
    void preorder(TreeNode* root) {
        if(root == nullptr) return;
        
        elements.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
};