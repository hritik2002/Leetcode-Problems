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
    int sum = 0;
    void getEvenSumGrandParent(TreeNode* root, TreeNode* parent, TreeNode* grandParent) {
        if(root == NULL) {
            return;
        }
        if(grandParent) {
            if(grandParent->val % 2 == 0) {
                sum += root->val;
            }
        }
        
        getEvenSumGrandParent(root->left, root, parent);
        getEvenSumGrandParent(root->right, root, parent);
        
        return;
    }
    int sumEvenGrandparent(TreeNode* root) {
        getEvenSumGrandParent(root, NULL, NULL);
        
        return sum;
    }
};