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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> counts(10, 0);
        return dfs(counts, root);
    }
    
    int dfs(vector<int> &counts, TreeNode* root) {
        if(root == nullptr) return 0;
        counts[root->val]++;
        if(root->left == nullptr && root->right == nullptr) {
            bool ispal = decide(counts);
            counts[root->val]--;
            return ispal ? 1 : 0;
        }
        
        int ans = 0;
        ans += dfs(counts, root->left);
        ans += dfs(counts, root->right);
        counts[root->val]--;
        return ans;
    }
    
    bool decide(vector<int> &counts) {
        int impares = 0;
        for(int i = 1; i < 10; ++i) {
            if(counts[i]%2 != 0) ++impares;
        }
        
        return impares <= 1;
    }
};