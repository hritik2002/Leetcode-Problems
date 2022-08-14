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
    bool isUnivalTree(TreeNode* root, TreeNode* parent = NULL) {
        if(root == NULL) {
            return true;
        }
        
        if(parent == NULL) {
            parent = root;
        }
        
        if(parent->val != root->val) {
            return false;
        }
        
        bool left = isUnivalTree(root->left, root);
        bool right = isUnivalTree(root->right, root);
        
        return left && right;
        
    }
};