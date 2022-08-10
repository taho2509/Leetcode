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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = generate(nums, 0, nums.size() - 1);
        return root;
    }
    
    TreeNode* generate(vector<int>& nums, int i, int j) {
        if(j == i){
            return new TreeNode(nums[i]);
        }
        if(i > j) return nullptr;
        
        int m = i + (j - i)/2;
        return new TreeNode(nums[m], generate(nums, i, m - 1), generate(nums, m + 1, j));
    }
};