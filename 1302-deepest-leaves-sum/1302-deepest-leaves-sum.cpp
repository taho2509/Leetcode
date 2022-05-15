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
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            int t = 0;
            for(int i = 0; i < n; ++i) {
                auto r = q.front();
                q.pop();
                t += r->val;
                if(r->left != nullptr) q.push(r->left);
                if(r->right != nullptr) q.push(r->right);
            }
            ans = t;
        }
        
        return ans;
    }
};