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
    int sum = 0, maxLevel = 0;    
    void dfs(TreeNode* root, int level) {
        if(root == NULL) {
            return;
        }
        if(level > maxLevel) {
            maxLevel = level;
            sum = 0;
        }
        if(level == maxLevel && root->left == NULL && root->right == NULL) {
            sum += root->val;
        }
        
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
        
        return;
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        
        return sum;
    }
};