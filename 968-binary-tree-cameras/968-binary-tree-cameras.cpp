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
    int ans = 0;
public:
    int minCameraCover(TreeNode* root) 
    {
        return (dfs(root) < 1 ? 1 : 0) + ans;
    }

    int dfs(TreeNode* root) 
    {
        if (!root) return 2;
        int left = dfs(root->left), right = dfs(root->right);
        if (left == 0 || right == 0) 
        {
            ++ans;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0;
    }
};