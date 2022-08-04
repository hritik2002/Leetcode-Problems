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
    int dfs(TreeNode* current_node, TreeNode* root){
        if(root == NULL)return 0;
        
        int left = dfs(current_node, root->left);
        int right = dfs(current_node, root->right);
        
        if(root->val > current_node->val){
            return left + right + root->val;
        }
        
        return left + right;
    }
    
    TreeNode* getBstToGst(TreeNode* root, TreeNode* current_node){
        if(current_node == NULL)
            return current_node;
        
        int sum = dfs(current_node, root) + current_node->val;
        TreeNode* new_root = new TreeNode(sum);
        
        TreeNode* left = getBstToGst(root, current_node->left);
        TreeNode* right = getBstToGst(root, current_node->right);
        
        new_root->left = left;
        new_root->right = right;
        
        return new_root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        return getBstToGst(root, root);
    }
};