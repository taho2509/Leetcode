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
map<pair<int,int>, vector<int>> m; 
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root, 0, 0);
        
        vector<vector<int>> ans;
        
        
        int column = -3000;
        for(auto it = m.begin(); it != m.end(); it++) {
            sort(it->second.begin(), it->second.end());
            if(it->first.first == column) {
                ans[ans.size() - 1].insert(ans[ans.size() - 1].end(), it->second.begin(), it->second.end());
            } else {
                ans.push_back(vector<int>(it->second.begin(), it->second.end()));
                column = it->first.first;
            }
        }
        
        return ans;
    }
    
    void traverse(TreeNode* root, int x, int y) {
        if(root == nullptr) return;
        m[{x,y}].push_back(root->val);
        traverse(root->left, x - 1, y + 1);
        traverse(root->right, x + 1, y + 1);
    }
};