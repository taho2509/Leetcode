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
map<tuple<TreeNode*, bool, bool>, int> DP;
public:
    int minCameraCover(TreeNode* root) {
        return min (find(root, true, false), find(root, false, false));
    }
    
    int find(TreeNode* r, bool cam, bool parentHaveCam) {
        if(r->left == nullptr && r->right == nullptr) {
            if(cam) return 1;
            if(parentHaveCam) return 0;
            return INT_MAX - 100;
        }
        
        if(DP.find({r, cam, parentHaveCam}) != DP.end()) return DP[{r, cam, parentHaveCam}];
        
        int left = 0, right = 0;
        int ans;
        
        if(cam) {
            if(r->left != nullptr) {
                left = min(find(r->left, false, cam), find(r->left, true, cam));
            }
            if(r->right != nullptr) {
                right = min(find(r->right, false, cam), find(r->right, true, cam));
            }
            ans = 1 + left + right;
        } else {
            if(parentHaveCam) {
                if(r->left != nullptr) {
                    left = min(find(r->left, false, cam), find(r->left, true, cam));
                }
                if(r->right != nullptr) {
                    right = min(find(r->right, false, cam), find(r->right, true, cam));
                }
                ans = left + right;
            } else {
                if(r->left == nullptr) {
                    ans = find(r->right, true, cam);
                } else if(r->right == nullptr) {
                    ans = find(r->left, true, cam);
                } else {
                    ans = min(
                        find(r->left, true, cam) 
                        + min(
                            find(r->right, true, cam),
                            find(r->right, false, cam)
                        ),
                        find(r->right, true, cam) 
                        + min(
                            find(r->left, true, cam),
                            find(r->left, false, cam)
                        )
                    );
                }
            }
        }
        DP[{r, cam, parentHaveCam}] = ans;
        return ans;
    }
};