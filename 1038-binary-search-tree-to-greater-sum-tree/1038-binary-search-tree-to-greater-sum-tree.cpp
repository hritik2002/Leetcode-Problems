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
    int getBstToGst(TreeNode* root, int &sum){
        if(root == NULL)return sum;
        
        int right = getBstToGst(root->right, sum);
        root->val += right;
        int left = getBstToGst(root->left, root->val);
        
        return left;
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL)return root;
        
        int sum = 0;
        getBstToGst(root, sum);
        
        return root;
    }
};