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
    bool isValidBST(TreeNode* root, long long int minValue = -9223372036854775807, long long int maxValue = 9223372036854775807) {
        if (root == NULL) {
            return true;
        }
        
        if (root->val >= maxValue) {
            return false;
        }
        if (root->val <= minValue) {
            return false;
        }
        
        bool leftSubTree = isValidBST (root->left, minValue, root->val);
        bool RightSubTree = isValidBST (root->right, root->val, maxValue);

        return leftSubTree && RightSubTree;
    }
};