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
    long long prev = -9223372036854775807;
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        
        bool left = isValidBST(root->left);
        
        if(prev >= root->val || left == false){
            return false;
        }else {
            prev = root->val;
        }
        
        bool right = isValidBST(root->right);
        
        return left && right;
    }
};