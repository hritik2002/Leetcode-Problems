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
    TreeNode* first ; TreeNode* second ; TreeNode* prev ;
    void helper(TreeNode* root){
        if(root==NULL)return;
        // Inorder traversal : Left -> root -> right
        helper(root->left);
        if(first==NULL && prev->val > root->val){
            first = prev ;
        }
        if(first!=NULL && prev->val > root->val){
            second = root ;
        }
        prev = root ;
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev = new TreeNode();
        prev->val = INT_MIN ;
        helper(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp ;
    }
};