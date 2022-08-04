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
    void getBstToGst(TreeNode* root, int &sum){
        if(root == NULL)return;
        
        getBstToGst(root->right, sum);
        sum += root->val;
        root->val = sum;
        getBstToGst(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL)return root;
        
        int sum = 0;
        getBstToGst(root, sum);
        
        return root;
    }
};