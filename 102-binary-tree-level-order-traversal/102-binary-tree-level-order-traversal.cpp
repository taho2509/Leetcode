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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            
            vector<int> level(n);
            for(int i = 0; i < n; ++i) {
                TreeNode* c = q.front();
                q.pop();
                level[i] = c->val;
                
                if(c->left != nullptr) q.push(c->left);
                if(c->right != nullptr) q.push(c->right);
            }
            
            ans.push_back(level);
        }
        
        return ans;
    }
};