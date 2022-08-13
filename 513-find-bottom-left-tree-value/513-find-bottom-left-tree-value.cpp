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
    int maxLevel = -1, ans = -1;
    int findBottomLeftValue(TreeNode* root, int level = 0) {
        if(root == NULL) {
            return ans;
        }
        findBottomLeftValue(root->left, level + 1);
        
        if(level > maxLevel) {
            ans = root->val;
            maxLevel = level;
        }
        
        findBottomLeftValue(root->right, level + 1);
        
        return ans;
    }
};