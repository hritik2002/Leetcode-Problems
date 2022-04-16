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
    int cur_sum = 0 ;
public:
    void dfs(TreeNode* root ){
        if (!root) return;
        if (root->right) dfs(root->right);
        
        root->val = (cur_sum += root->val);
        if (root->left) dfs(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        
        dfs(root);
        return root;
    }
};