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
    bool match(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL && root == NULL) {
            return true;
        }
        if(root == NULL || subRoot == NULL) {
            return false;
        }
        
        if(root->val != subRoot->val) {
            return false;
        }
        
        bool left = match(root->left, subRoot->left);
        bool right = match(root->right, subRoot->right);
        
        return left && right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) {
            return false;
        }
        
        return match(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};