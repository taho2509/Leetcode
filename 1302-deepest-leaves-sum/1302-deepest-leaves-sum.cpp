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
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return sum(root).first;
    }
    
    pair<int,int> sum(TreeNode* root) {
        if(root == nullptr) return {0,0};
        
        auto [vleft, hleft] = sum(root->left);
        auto [vright, hright] = sum(root->right);
        if(vleft != 0 && vright != 0) {
            if(hleft == hright) return {vleft + vright, hleft + 1};
            if(hleft > hright) return {vleft, hleft + 1};
            return {vright, hright + 1};
        } else if(vleft != 0) {
            return {vleft, hleft + 1};
        } else if(vright != 0) {
            return {vright, hright + 1};
        } else {
            return {root->val, 1};
        }
    }
};