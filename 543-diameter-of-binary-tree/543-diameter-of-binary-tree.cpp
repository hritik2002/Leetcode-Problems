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
    int diameter = 0;
    
    int getDiameter(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int left = getDiameter(root->left);
        int right = getDiameter(root->right);
        
        if(diameter < left + right) {
            diameter = left + right;
        }
        
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        getDiameter(root);
        
        return diameter;
    }
};