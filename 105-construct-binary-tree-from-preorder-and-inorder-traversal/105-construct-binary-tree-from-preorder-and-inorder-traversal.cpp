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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int startIndex, int endIndex, int & rootIndex){
        if(startIndex > endIndex)return NULL;
        
        TreeNode* root = new TreeNode(preorder[rootIndex++]);
        
        int inorderRootIndex = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        
        root->left = buildTree(preorder, inorder, startIndex, inorderRootIndex - 1, rootIndex);
        root->right = buildTree(preorder, inorder, inorderRootIndex + 1, endIndex, rootIndex);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size(), rootIndex = 0;
        
        return buildTree(preorder, inorder, 0, n - 1, rootIndex);
    }
};