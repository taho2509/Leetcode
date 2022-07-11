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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};

        vector<int> ans;
        int currentLevel = -1;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        
        while(!q.empty()) {
            auto c = q.front();
            q.pop();
            int level = c.first;
            TreeNode* node = c.second;
            if(level > currentLevel) {
                currentLevel = level;
                ans.push_back(node->val);
            }
            
            if(node->right != nullptr) {
                q.push({level + 1, node->right});
            }
            if(node->left != nullptr) {
                q.push({level + 1, node->left});
            }
        }
        
        
        return ans;
    }
};