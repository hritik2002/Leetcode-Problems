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
    
    int getBalanced(TreeNode* root){
        if(root == NULL)return 0;
        
        int left_child = getBalanced(root->left);
        int right_child = getBalanced(root->right);
        
        if(left_child == -1 || right_child == -1){
            return -1;
        }
        
        if(abs(left_child - right_child) > 1)return -1;
        
        return max(left_child, right_child) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)return true;
        
        int isBalanced = getBalanced(root);
        
        if(isBalanced == -1)return false;
        
        return true;
    }
};