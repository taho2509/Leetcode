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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            double average = 0;
            int n = q.size();
            for(int i = 0; i < n; ++i) {
                TreeNode* current = q.front();
                q.pop();
                average += (1.0/(i + 1)*((double)current->val - average));
                
                if(current->left != nullptr) q.push(current->left);
                if(current->right != nullptr) q.push(current->right);
            }
            ans.push_back(average);
        }
        
        return ans;
    }
};